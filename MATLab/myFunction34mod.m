function [ F ] = myFunction34mod( x )

a2 = getGlobalAcc2;
Rmod_2 = getGlobalRmod_2;
j1 = getGlobalJ1;
j2 = getGlobalJ2;


%RG0 = [1 0 0; 0 1 0; 0 0 1];
R0G = getGlobalR0G;
R01 = [cos(j1) -sin(j1) 0; 0 0 1; -sin(j1) -cos(j1) 0];
R12 = [cos(j2) -sin(j2) 0; 0 0 -1; sin(j2) cos(j2) 0];
R02 = R01 * R12;

R20 = transpose(R02);
%R0G = transpose(RG0);

R23 = [cos(x(1)) -sin(x(1)) 0; 0 0 1; -sin(x(1)) -cos(x(1)) 0];
R34 = [cos(x(2)) -sin(x(2)) 0; 0 0 -1; sin(x(2)) cos(x(2)) 0];
R24 = R23 * R34;
R4A = [0 0 1; 0 1 0;-1 0 0];

RA4 = transpose(R4A);
R42 = transpose(R24);

%F = Rmod_2*RA4*R42*R20*R0G*[0;0;1]-a2;
F = RA4*R42*R20*R0G*[0;0;1]-a2;
end

