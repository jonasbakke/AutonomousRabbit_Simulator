function [x_intersect, y_intersect] = find_intersection(a1, b1, a2, b2)
        if a1 == a2
            x_intersect = [];
            y_intersect = [];
            return;
        end

        x_intersect = (b2 - b1) / (a1 - a2);
        y_intersect = a1 * x_intersect + b1;
    end