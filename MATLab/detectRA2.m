%Detect RA2


syms j1 j2 x y z real
acc1 =  [x; y; z];

RG0 = [1 0 0; 0 1 0; 0 0 1];
R01 = [cos(j1) -sin(j1) 0; 0 0 1; -sin(j1) -cos(j1) 0];
R12 = [cos(j2) -sin(j2) 0; 0 0 -1; sin(j2) cos(j2) 0];
R02 = R01 * R12;

syms a b g real

R2A = [cos(a)*cos(b) cos(a)*sin(b)*sin(g)-sin(a)*cos(g) cos(a)*sin(b)*cos(g)+sin(a)*sin(g);
    sin(a)*cos(b) sin(a)*sin(b)*sin(g)+cos(a)*cos(g) sin(a)*sin(b)*cos(g)-cos(a)*sin(g);
    -sin(b) cos(b)*sin(g) cos(b)*cos(g)];
    
R20 = transpose(R02);
RA2 = transpose(R2A);
R0G = transpose(RG0);
acc1 = RA2*R20*R0G*[0;0;1]

[acc1, acc2, acc3, acc4, joints] = readInput(0,50);
setGlobalJ1(joints(1,1));
setGlobalJ2(joints(1,2));
acc1_Norm = Normalize(acc1(1,1:3));
setGlobalAcc1(acc1_Norm);
%options = optimoptions('fsolve','Display','iter');
    
x0 =[0,0,0];
[x,fval] = fsolve(@myFunctionRA2,x0);%,options);
a = x(1,1);
b = x(1,2);
g = x(1,3);

R2A = [cos(a)*cos(b) cos(a)*sin(b)*sin(g)-sin(a)*cos(g) cos(a)*sin(b)*cos(g)+sin(a)*sin(g);
    sin(a)*cos(b) sin(a)*sin(b)*sin(g)+cos(a)*cos(g) sin(a)*sin(b)*cos(g)-cos(a)*sin(g);
    -sin(b) cos(b)*sin(g) cos(b)*cos(g)]
RA2 = transpose(R2A)
 
R2A = [0 0 -1 ; 1 0 0; 0 -1 0];
%RA2 = transpose(R2A)


R2A = rotx(0.1)*R2A