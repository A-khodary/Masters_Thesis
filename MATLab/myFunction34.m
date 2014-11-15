function [ F ] = myFunction34( x )

j1 = getGlobalJ1;
j2 = getGlobalJ2;
a2 = getGlobalAcc2;

F = [ cos(j2)*sin(j1)*sin(x(1)) - cos(j1)*cos(x(1)) - a2(1,1);
    cos(x(2))*sin(j1)*sin(j2) + cos(j1)*sin(x(1))*sin(x(2)) + cos(j2)*cos(x(1))*sin(j1)*sin(x(2)) - a2(2,1) ;
    sin(j1)*sin(j2)*sin(x(2)) - cos(j1)*cos(x(2))*sin(x(1)) - cos(j2)*cos(x(1))*cos(x(2))*sin(j1) - a2(3,1)];
end

