clc;
clear all;

% Input: Generator Matrix
g = input('Enter the generator matrix G:\n');

% Display Generator Matrix
disp('G =');
disp(g);

% Determine Code Parameters [n, k]
[n, k] = size(transpose(g));
disp('The order of the linear block code (n, k) is:');
disp(['n = ', num2str(n), ', k = ', num2str(k)]);

% Generate All Possible Input Messages
u = zeros(2^k, k);
for i = 1:2^k
    for j = k:-1:1
        if rem(i-1, 2^(-j + k + 1)) >= 2^(-j + k)
            u(i, j) = 1;
        else
            u(i, j) = 0;
        end
    end
end

% Display All Possible Codewords
disp('The possible codewords are:');
c = rem(u * g, 2);
disp(c);

% Calculate Minimum Hamming Distance
weights = sum(c(2:end, :)'); % Skip the all-zero codeword
d_min = min(weights);
disp('The minimum Hamming distance d_min for the given block code is:');
disp(d_min);

% Received Codeword
r = input('Enter the received code word as a row vector:\n');

% Parity and Syndrome Matrix (for error detection)
p = g(:, n - k + 2:n);
h = [transpose(p), eye(n - k)];
ht = transpose(h);

disp('Hamming parity-check matrix H is:');
disp(h);
disp('Transpose of H (used for syndrome calculation):');
disp(ht);

% Syndrome Calculation
s = rem(r * ht, 2);
disp('Syndrome of the received codeword is:');
disp(s);

% Error Detection and Correction
error_bit = 0;
for i = 1:size(ht, 2)
    if isequal(ht(:, i)', s)
        r(i) = 1 - r(i); % Flip the bit
        error_bit = i;
        break;
    end
end

% Display Correction
if error_bit == 0
    disp('No error detected.');
else
    disp(['Error detected and corrected in bit: ', num2str(error_bit)]);
end
disp('The corrected codeword is:');
disp(r);
