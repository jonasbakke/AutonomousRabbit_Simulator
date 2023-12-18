N_h = size(vout_rearCamera, 1);
N_w = size(vout_rearCamera, 2);
N_c = size(vout_rearCamera, 3);
N_t = size(vout_rearCamera, 4);
M = N_h*N_w;

DISTANCE = out.DISTANCE;

N = min(N_t, length(DISTANCE));

data = zeros(M+1,N);
for n = 1:N
    data(1,n) = DISTANCE(n);
    data(2:end,n) = reshape(rgb2gray( vout_rearCamera(:,:,:,n) ), [M,1]);
end

for i = 2:M
    for j = N
        data(i,j) = data(i,j);
    end
end





