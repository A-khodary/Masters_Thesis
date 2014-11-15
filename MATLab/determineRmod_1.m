function [ Rmod ] = determineRmod_1

% Algorithm Setup
options = optimoptions('fsolve');

% Determine Joints One and Two
x0 = eye(3);
[x,fval] = fsolve(@myFunctionRmod_1,x0,options);
Rmod = x;

end