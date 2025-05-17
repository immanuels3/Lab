clc;
clear all;

% Prompt user for generator matrix
g = input('Enter the generator matrix G (e.g. [1 0 0 1 1 0 1; 0 1 0 1 0 1 1; 0 0 1 0 1 1 1]):\n');

% Display Generator Matrix
disp('G =');
disp(g);

% Determine code parameters (n, k)
[n, k] = size(transpose(g));
printf('The order of the linear block code (n, k) is: n = %d, k = %d\n', n, k);

% Generate all possible input vectors u
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

% Generate all possible codewords
c = mod(u * g, 2);
disp('The possible codewords are:');
disp(c);

% Minimum Hamming Distance Calculation
weights = sum(c(2:end, :)'); % exclude all-zero codeword
d_min = min(weights);
printf('The minimum Hamming distance d_min = %d\n', d_min);

% Ask for received codeword
r = input('Enter the received code word as a row vector (e.g. [1 0 1 1 1 0 0]):\n');

% Construct parity matrix P and parity-check matrix H
p = g(:, n-k+2:n);
h = [transpose(p), eye(n-k)];
ht = transpose(h);

disp('Hamming parity-check matrix H is:');
disp(h);
disp('Transpose of H (for syndrome calculation):');
disp(ht);

% Syndrome calculation
s = mod(r * ht, 2);
disp('Syndrome:');
disp(s);

% Syndrome decoding to correct 1-bit error
error_bit = 0;
for i = 1:size(ht, 2)
    if isequal(ht(:, i)', s)
        r(i) = 1 - r(i);  % flip the erroneous bit
        error_bit = i;
        break;
    end
end

if error_bit == 0
    disp('No error detected.');
else
    printf('Error detected in bit: %d\n', error_bit);
end

disp('Corrected codeword:');
disp(r);
