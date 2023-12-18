clc

lane = 3;
w = 1.22;  % Width of lane
A = 85.33; % Length of the straight portion
R = 36.5; % Radius of innermost white line curve
R_lane = R + w*lane - w/2; % Radius of center of the lane used
C_lane = pi*R_lane; % Circumference of the curved portion of the path


% Runner starting position. x0 and theta0 should not be changed. Set y0
% between 0 and -A
%to set where the runner should begin. y0=0 will start the runner at the
% beginning of a curve, and y0 = -A will start the runner at the beginning
% of a straight lane.
x0 = -R_lane;
y0 = -45;
theta0 = pi/2;


v = 5; % Runner velocity [m/s]

%Start of first curve
t1 = -y0/v;

%End of first curve
t2 = t1 + C_lane/v;

%Start of second curve
t3 = t2 + A/v;

%End of second curve, back to start
t4 = t3 + C_lane/v;

n = 10000; % Number of time steps
T = linspace(0, t4 ,n);
for i = 1:n
    if T(i) <= t1
        n1 = i;
    end

    if T(i) <= t2
        n2 = i;
    end
    if T(i) <= t3
        n3 = i;
    end
    if T(i) <= t4
        n4 = i;
    end
end

THETA = [theta0*ones(1,n1),...
    linspace(theta0, theta0-pi, n2-n1),...
    (theta0-pi)*ones(1, n3-n2),...
    linspace(theta0-pi, theta0-2*pi, n4-n3)];



X = zeros(1,n);
X(1) = x0;
Y = zeros(1,n);
Y(1) = y0;
delta_t = T(2)-T(1);
for i = 2:n
    X(i) = X(i-1) + v*cos(THETA(i))*delta_t;
    Y(i) = Y(i-1) + v*sin(THETA(i))*delta_t;
end

runnerPath = timeseries([THETA; X; Y], T);