function delta = steering_controller(image)
%GET_STEERING_ANGLE Summary of this function goes here
%   Detailed explanation goes here




% Get heigth and width of image
heigth = size(image, 1);
width = size(image, 2);

% Get edges

sigma = 0.33;    % UNIQUE for MATLAB
% Compute the median of the single channel pixel intensities
v = double(median(image(:)))/255;

% % Apply automatic Canny edge detection using the computed median
lower = max(0.0001, (1.0 - sigma) * v);   % Added div 255!
upper = min(0.9999, (1.0 + sigma) * v);   % Added div 255!

if upper <= lower
    lower = 0.1;
    upper = 0.9;
end

edges = edge(image, 'Canny', [lower, upper]);   


% Example angle control
angle_setpoint = -90;  % The desired angle you want to maintain
angle_pid = PIDcontroller(0.01, 0.025, 0.0, angle_setpoint);

% Example position control
position_setpoint = width/2;  % The desired position you want to reach
position_pid = PIDcontroller(0.0025, 0.00025, 0.0, position_setpoint);


% Normal Hough transform. Results in rho, theta
[H, T, R] = hough(edges);
% imshow(H,[],'XData',T,'YData',R,...
%         'InitialMagnification','fit');
% xlabel('\theta'), ylabel('\rho');
% axis on, axis normal, hold on;

P  = houghpeaks(H,5,'threshold',ceil(0.3*max(H(:))));
%x = T(P(:,2)); y = R(P(:,1));
%plot(x,y,'s','color','white');

lines = houghlines(edges,T,R,P,'FillGap',5,'MinLength',7);
figure(1), imshow(image), hold on
max_len = 0;
for k = 1:length(lines)
   xy = [lines(k).point1; lines(k).point2];
   plot(xy(:,1),xy(:,2),'LineWidth',2,'Color','green');

   %Plot beginnings and ends of lines
   plot(xy(1,1),xy(1,2),'x','LineWidth',2,'Color','yellow');
   plot(xy(2,1),xy(2,2),'x','LineWidth',2,'Color','red');

   % Determine the endpoints of the longest line segment
   len = norm(lines(k).point1 - lines(k).point2);
   if ( len > max_len)
      max_len = len;
      %xy_long = xy;
   end
end
% Draw the detected lines on the original image
if ~isempty(lines)
    %disp('--------');
    thetas = zeros(1, size(lines,2));
    % disp(size(lines(1)))
    for i =1:size(lines,2)
        thetas(i) = lines(i).theta;
    end
    left_count = sum(thetas<60 & thetas>0);
    % disp("left count")
    % disp(left_count)
    line_left  = NaN(left_count, 2);
    line_right = NaN(sum(thetas<0 & thetas>-60), 2);
    i = 1;
    j = 1;
    for k = 1:numel(lines)
        rho = lines(k).rho;
        theta = lines(k).theta;
        a = cos(deg2rad(theta));
        b = sin(deg2rad(theta));
        x0 = a * rho;
        y0 = b * rho;
        %plot(x0,y0,'x','LineWidth',2,'Color','black','x','LineWidth',2,'Color','yellow')
        x1 = round(x0 + 1000 * (-b));
        y1 = round(y0 + 1000 * (a));
        x2 = round(x0 - 1000 * (-b));
        y2 = round(y0 - 1000 * (a));

        if theta < 60 && theta > 0 
            line_left(2*i-1,:) = [x1, y1];
            line_left(2*i,:)   = [x2, y2];
            i = i+1;
        elseif theta < 0 && theta > -60
            line_right(2*j-1,:) = [x1, y1];
            line_right(2*j,:)   = [x2, y2];
            j = j+1;
        else
            continue;
        end
    end
    %disp('------------');
else
    line_left  = [0, 0];
    line_right = [0, 0];
end

for k = 1:length(line_left)/2-1
   xy = line_left(k*2:k*2+1,:);
   plot(xy(:,1),xy(:,2),'LineWidth',2,'Color','green');

   %Plot beginnings and ends of lines
   plot(xy(1,1),xy(1,2),'x','LineWidth',2,'Color','yellow');
   plot(xy(2,1),xy(2,2),'x','LineWidth',2,'Color','red');
end
for k = 1:length(line_right)/2-1
   xy = line_right(k*2:k*2+1,:);
   plot(xy(:,1),xy(:,2),'LineWidth',2,'Color','green');

   %Plot beginnings and ends of lines
   plot(xy(1,1),xy(1,2),'x','LineWidth',2,'Color','yellow');
   plot(xy(2,1),xy(2,2),'x','LineWidth',2,'Color','red');
   plot(10,10,'x','LineWidth',2,'Color','blue');
end

% Initial guesses for the line parameters
initial_params = [1, 1];
options = optimoptions('fminunc', 'Display', 'off');

% Perform the optimization for the left line
result1 = fminunc(@(params) error_function(params, line_left), initial_params, options);
a1_optimal = result1(1);
b1_optimal = result1(2);
%disp(['Line: y1 = ', num2str(a1_optimal, '%.2f'), 'x + ', num2str(b1_optimal, '%.2f')]);

% Perform the optimization for the right line
result2 = fminunc(@(params) error_function(params, line_right), initial_params, options);
a2_optimal = result2(1);
b2_optimal = result2(2);
%disp(['Line: y2 = ', num2str(a2_optimal, '%.2f'), 'x + ', num2str(b2_optimal, '%.2f')]);


hold off
% iteration = 0;
% filename = strcat('images/',string(iteration),'.png');
% exportgraphics(gcf,filename)
% disp(filename)



[x_intersect, y_intersect] = find_intersection(a1_optimal, b1_optimal, a2_optimal, b2_optimal);
%disp(['Intersection Point: (', num2str(x_intersect), ', ', num2str(y_intersect), ')']);
if isempty(x_intersect) || isempty(y_intersect)
    delta = 0;
    %disp(steering_angle)
    return;
end
y_center = heigth;
x_center = find_intersection_with_y_equals_constant(a1_optimal,b1_optimal,a2_optimal,b2_optimal,y_center);


% Calculate the angle based on the intersection and center points
angle_radians = atan2(y_intersect - y_center, x_intersect - x_center);
angle = rad2deg(angle_radians);

position = x_center;

% Simulate angle control
angle_control_signal = -angle_pid.compute(angle);   % Usikkert fortegn

% Simulate position control
position_control_signal = position_pid.compute(position);

delta = deg2rad( angle_control_signal + position_control_signal );



end
