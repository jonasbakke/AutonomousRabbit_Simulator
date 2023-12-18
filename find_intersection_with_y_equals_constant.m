function intersection = find_intersection_with_y_equals_constant(a1, b1, a2, b2, y_constant)
    % Solve for x when y = y_constant in both line equations
    x1 = (y_constant - b1) / a1;
    x2 = (y_constant - b2) / a2;

    % Calculate the average of the two x-values
    intersection = (x1 + x2) / 2;
end
