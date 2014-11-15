function [ tgt ] = Normalize(acc)
% Normalizes the accelerometer input and arranges it into vector form.

V = [double(acc(1,1)),double(acc(1,2)),double(acc(1,3))]; 

normalized_V = V/norm(V);
tgt(1,1) = normalized_V(1,1);
tgt(2,1) = normalized_V(1,2);
tgt(3,1) = normalized_V(1,3);
end