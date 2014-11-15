function [ F ] = myFunction56( x )

j1 = getGlobalJ1;
j2 = getGlobalJ2;
j3 = getGlobalJ3;
j4 = getGlobalJ4;
a3 = getGlobalAcc3;

R0G = getGlobalR0G;

R01 = [cos(j1) -sin(j1) 0; 0 0 1; -sin(j1) -cos(j1) 0];
R12 = [cos(j2) -sin(j2) 0; 0 0 -1; sin(j2) cos(j2) 0];
R02 = R01 * R12;
R20 = transpose(R02);

R23 = [cos(j3) -sin(j3) 0; 0 0 1; -sin(j3) -cos(j3) 0];
R34 = [cos(j4) -sin(j4) 0; 0 0 -1; sin(j4) cos(j4) 0];
R24 = R23 * R34;
R42 = transpose(R24);


R45 = [cos(x(1)) -sin(x(1)) 0; 0 0 1; -sin(x(1)) -cos(x(1)) 0];
R56 = [cos(x(2)) -sin(x(2)) 0; 0 0 -1; sin(x(2)) cos(x(2)) 0];
R46 = R45 * R56;
R6A = [-1 0 0; 0 0 1; 0 1 0];

R64 = transpose(R46);
RA6 = transpose(R6A);

%F = Rmod_2*RA4*R42*R20*R0G*[0;0;1]-a2;
F = RA6*R64*R42*R20*R0G*[0;0;1]-a3;



% 
% % 
% % F = [  cos(j1)*(cos(j3)*cos(x(2))*sin(x(1)) - sin(j3)*sin(j4)*sin(x(2)) + cos(j4)*cos(x(1))*cos(x(2))*sin(j3)) - sin(j1)*sin(j2)*(cos(j4)*sin(x(2)) + cos(x(1))*cos(x(2))*sin(j4)) - cos(j2)*sin(j1)*(cos(j3)*sin(j4)*sin(x(2)) + cos(x(2))*sin(j3)*sin(x(1)) - cos(j3)*cos(j4)*cos(x(1))*cos(x(2))) - a3(1,1);
% %     cos(j1)*(cos(j3)*cos(x(1)) - cos(j4)*sin(j3)*sin(x(1))) - cos(j2)*sin(j1)*(cos(x(1))*sin(j3) + cos(j3)*cos(j4)*sin(x(1))) + sin(j1)*sin(j2)*sin(j4)*sin(x(1)) - a3(2,1);
% %     cos(j1)*(cos(x(2))*sin(j3)*sin(j4) + cos(j3)*sin(x(1))*sin(x(2)) + cos(j4)*cos(x(1))*sin(j3)*sin(x(2))) + sin(j1)*sin(j2)*(cos(j4)*cos(x(2)) - cos(x(1))*sin(j4)*sin(x(2))) + cos(j2)*sin(j1)*(cos(j3)*cos(x(2))*sin(j4) - sin(j3)*sin(x(1))*sin(x(2)) + cos(j3)*cos(j4)*cos(x(1))*sin(x(2))) - a3(3,1)];
% 
%  F = [cos(j1)*(cos(j3)*cos(x(2))*sin(x(1)) - sin(j3)*sin(j4)*sin(x(2)) + cos(j4)*cos(x(1))*cos(x(2))*sin(j3)) - sin(j1)*sin(j2)*(cos(j4)*sin(x(2)) + cos(x(1))*cos(x(2))*sin(j4)) - cos(j2)*sin(j1)*(cos(j3)*sin(j4)*sin(x(2)) + cos(x(2))*sin(j3)*sin(x(1)) - cos(j3)*cos(j4)*cos(x(1))*cos(x(2))) - a3(1,1);
%                                                                                                                  cos(j1)*(cos(j3)*cos(x(1)) - cos(j4)*sin(j3)*sin(x(1))) - cos(j2)*sin(j1)*(cos(x(1))*sin(j3) + cos(j3)*cos(j4)*sin(x(1))) + sin(j1)*sin(j2)*sin(j4)*sin(x(1)) - a3(2,1);
%  cos(j1)*(cos(x(2))*sin(j3)*sin(j4) + cos(j3)*sin(x(1))*sin(x(2)) + cos(j4)*cos(x(1))*sin(j3)*sin(x(2))) + sin(j1)*sin(j2)*(cos(j4)*cos(x(2)) - cos(x(1))*sin(j4)*sin(x(2))) + cos(j2)*sin(j1)*(cos(j3)*cos(x(2))*sin(j4) - sin(j3)*sin(x(1))*sin(x(2)) + cos(j3)*cos(j4)*cos(x(1))*sin(x(2))) - a3(3,1)];
%  
end

