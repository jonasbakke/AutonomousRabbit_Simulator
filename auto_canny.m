function edged = auto_canny(image)
    sigma = 0.33;    % UNIQUE for MATLAB
    % Compute the median of the single channel pixel intensities
    v = double(median(image(:)))/255;
    
    % Apply automatic Canny edge detection using the computed median
    lower = max(0, (1.0 - sigma) * v);   % Added div 255!
    upper = min(1, (1.0 + sigma) * v);   % Added div 255!
    
    edged = edge(image, 'Canny', [lower, upper]);   
    
    % Display the lower and upper thresholds
    disp(lower);
    disp(upper);
end