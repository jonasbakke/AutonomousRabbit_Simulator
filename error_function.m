function error = error_function(params, data)
        a = params(1);
        b = params(2);
        x = data(:,1);
        y = data(:,2);
        predicted = a * x + b;
        error = sum((y - predicted).^2);
    end