classdef PIDcontroller
    properties
        kp
        ki
        kd
        setpoint
        prev_error
        integral
    end
    
    methods
        function obj = PIDcontroller(kp, ki, kd, setpoint)
            obj.kp = kp;
            obj.ki = ki;
            obj.kd = kd;
            obj.setpoint = setpoint;
            obj.prev_error = 0;
            obj.integral = 0;
        end
        
        function control_signal = compute(obj, current_value)
            error = obj.setpoint - current_value;

            % Proportional term
            P = obj.kp * error;

            % Integral term
            obj.integral = obj.integral + error;
            I = obj.ki * obj.integral;

            % Derivative term
            D = obj.kd * (error - obj.prev_error);

            % Compute the control signal
            control_signal = P + I + D;

            % Update the previous error for the next iteration
            obj.prev_error = error;
        end
    end
end
