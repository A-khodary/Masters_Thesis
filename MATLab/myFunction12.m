function [ F ] = myFunction12( x )

a1 = getGlobalAcc1;

F = [  sin(x(1))*sin(x(2))-a1(1,1);
        -cos(x(1))-a1(2,1);
 cos(x(2))*sin(x(1))-a1(3,1)];

end

