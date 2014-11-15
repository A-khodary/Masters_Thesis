function [ F ] = myFunction7( x )

j1 = getGlobalJ1;
j2 = getGlobalJ2;
j3 = getGlobalJ3;
j4 = getGlobalJ4;
j5 = getGlobalJ5;
j6 = getGlobalJ6;
a4 = getGlobalAcc4;

R0G = getGlobalR0G;

R01 = [cos(j1) -sin(j1) 0; 0 0 1; -sin(j1) -cos(j1) 0];
R12 = [cos(j2) -sin(j2) 0; 0 0 -1; sin(j2) cos(j2) 0];
R02 = R01 * R12;
R20 = transpose(R02);

R23 = [cos(j3) -sin(j3) 0; 0 0 1; -sin(j3) -cos(j3) 0];
R34 = [cos(j4) -sin(j4) 0; 0 0 -1; sin(j4) cos(j4) 0];
R24 = R23 * R34;
R42 = transpose(R24);


R45 = [cos(j5) -sin(j5) 0; 0 0 1; -sin(j5) -cos(j5) 0];
R56 = [cos(j6) -sin(j6) 0; 0 0 -1; sin(j6) cos(j6) 0];
R46 = R45 * R56;
R64 = transpose(R46);

R67 = [cos(x(1)) -sin(x(1)) 0; 0 0 1; -sin(x(1)) -cos(x(1)) 0];
R7A = [0 -1 0; 1 0 0; 0 0 1];

R76 = transpose(R67);
RA7 = transpose(R7A);

%F = Rmod_2*RA4*R42*R20*R0G*[0;0;1]-a2;
F = RA7*R76*R64*R42*R20*R0G*[0;0;1]-a4;

% 
% F = [cos(j2)*sin(j1)*(sin(j3)*(cos(j5)*cos(x(1)) - cos(j6)*sin(j5)*sin(x(1))) + cos(j3)*cos(j4)*(cos(x(1))*sin(j5) + cos(j5)*cos(j6)*sin(x(1))) - cos(j3)*sin(j4)*sin(j6)*sin(x(1))) - sin(j1)*sin(j2)*(sin(j4)*(cos(x(1))*sin(j5) + cos(j5)*cos(j6)*sin(x(1))) + cos(j4)*sin(j6)*sin(x(1))) - cos(j1)*(cos(j3)*(cos(j5)*cos(x(1)) - cos(j6)*sin(j5)*sin(x(1))) - cos(j4)*sin(j3)*(cos(x(1))*sin(j5) + cos(j5)*cos(j6)*sin(x(1))) + sin(j3)*sin(j4)*sin(j6)*sin(x(1))) - a4(1,1);
%     sin(j1)*sin(j2)*(sin(j4)*(sin(j5)*sin(x(1)) - cos(j5)*cos(j6)*cos(x(1))) - cos(j4)*cos(x(1))*sin(j6)) - cos(j1)*(cos(j4)*sin(j3)*(sin(j5)*sin(x(1)) - cos(j5)*cos(j6)*cos(x(1))) - cos(j3)*(cos(j5)*sin(x(1)) + cos(j6)*cos(x(1))*sin(j5)) + cos(x(1))*sin(j3)*sin(j4)*sin(j6)) - cos(j2)*sin(j1)*(sin(j3)*(cos(j5)*sin(x(1)) + cos(j6)*cos(x(1))*sin(j5)) + cos(j3)*cos(j4)*(sin(j5)*sin(x(1)) - cos(j5)*cos(j6)*cos(x(1))) + cos(j3)*cos(x(1))*sin(j4)*sin(j6)) - a4(2,1);
%     cos(j1)*(cos(j6)*sin(j3)*sin(j4) + cos(j3)*sin(j5)*sin(j6) + cos(j4)*cos(j5)*sin(j3)*sin(j6)) + sin(j1)*sin(j2)*(cos(j4)*cos(j6) - cos(j5)*sin(j4)*sin(j6)) + cos(j2)*sin(j1)*(cos(j3)*cos(j6)*sin(j4) - sin(j3)*sin(j5)*sin(j6) + cos(j3)*cos(j4)*cos(j5)*sin(j6)) - a4(3,1)];

end

