function [ F ] = myFunction12mod( x )

a1 = getGlobalAcc1;
Rmod = getGlobalRmod;

%RG0 = [1 0 0; 0 1 0; 0 0 1];
R0G = getGlobalR0G;
R01 = [cos(x(1)) -sin(x(1)) 0; 0 0 1; -sin(x(1)) -cos(x(1)) 0];
R12 = [cos(x(2)) -sin(x(2)) 0; 0 0 -1; sin(x(2)) cos(x(2)) 0];
R02 = R01 * R12;
R2A = [0 0 -1 ; 1 0 0; 0 -1 0];

R20 = transpose(R02);
RA2 = transpose(R2A);
%R0G = transpose(RG0);

%F = Rmod*RA2*R20*R0G*[0;0;1]-a1;
F = RA2*R20*R0G*[0;0;1]-a1;
end

