function v = speed_controller(distance)
persistent prev_error integral_term

%SPEEDCONTROLLER Summary of this function goes here
%   Detailed explanation goes here

if isempty(prev_error)
    prev_error = 0;
    integral_term = 0;
end



kp = 10;
ki = 0;
kd = 1;

distance_reference = 10;
distance_pid = PIDcontroller(kp, ki, kd, distance_reference);


%error = distance_reference - distance;
%integral_term = integral_term + error;

% v = kp * error ...
%     + ki * integral_term ...
%     + kd * (error - prev_error);

%prev_error = error;

v = distance_pid.compute(distance);
end

