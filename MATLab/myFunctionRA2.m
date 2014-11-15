function [ F ] = myFunctionRA2( x )

j1 = getGlobalJ1;
j2 = getGlobalJ2;
a1 = getGlobalAcc1;

F = [cos(x(2))*sin(x(1))*sin(j1)*sin(j2) - cos(x(1))*cos(x(2))*cos(j2)*sin(j1) - cos(j1)*sin(x(2)) - a1(1,1);
 cos(j2)*sin(j1)*(cos(x(3))*sin(x(1)) - cos(x(1))*sin(x(2))*sin(x(3))) + sin(j1)*sin(j2)*(cos(x(1))*cos(x(3)) + sin(x(1))*sin(x(2))*sin(x(3))) + cos(x(2))*cos(j1)*sin(x(3)) - a1(2,1);
 cos(x(2))*cos(x(3))*cos(j1) - sin(j1)*sin(j2)*(cos(x(1))*sin(x(3)) - cos(x(3))*sin(x(1))*sin(x(2))) - cos(j2)*sin(j1)*(sin(x(1))*sin(x(3)) + cos(x(1))*cos(x(3))*sin(x(2))) - a1(3,1)];
 
end

