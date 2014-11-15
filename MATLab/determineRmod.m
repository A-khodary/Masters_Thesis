function [ Rmod ] = determineRmod

% Algorithm Setup
options = optimoptions('fsolve');

% Determine Joints One and Two
x0 = eye(3);
[x,fval] = fsolve(@myFunctionRmod,x0,options);
Rmod = x;

end