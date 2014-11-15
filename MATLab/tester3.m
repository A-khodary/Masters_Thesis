
syms j1 j2 x y z real
acc1 =  [x; y; z];

RG0 = [1 0 0; 0 1 0; 0 0 1];

R01 = [cos(j1) -sin(j1) 0; 0 0 1; -sin(j1) -cos(j1) 0];
R10 = transpose(R01);

R12 = [cos(j2) -sin(j2) 0; 0 0 -1; sin(j2) cos(j2) 0];
R21 = transpose(R12);

R02 = R01 * R12;
R2A = [0 0 -1 ; 1 0 0; 0 -1 0];

R20 = transpose(R02);
RA2 = transpose(R2A);
R0G = transpose(RG0);
acc1 = RA2*R20*R0G*[0;0;1];

syms j3 j4 real
R23 = [cos(j3) -sin(j3) 0; 0 0 1; -sin(j3) -cos(j3) 0];
R32 = transpose(R23);
R34 = [cos(j4) -sin(j4) 0; 0 0 -1; sin(j4) cos(j4) 0];
R43 = transpose(R34);
R24 = R23 * R34;
R4A = [0 0 1; 0 1 0;-1 0 0];

RA4 = transpose(R4A);
R42 = transpose(R24);

syms j5 j6 real
R45 = [cos(j5) -sin(j5) 0; 0 0 1; -sin(j5) -cos(j5) 0];
R54 = transpose(R45);
R56 = [cos(j6) -sin(j6) 0; 0 0 -1; sin(j6) cos(j6) 0];
R65 = transpose(R56);
R46 = R45 * R56;
R64 = transpose(R46);

syms j7 real
R67 = [cos(j7) -sin(j7) 0; 0 0 1; -sin(j7) -cos(j7) 0]
R7A = [0 -1 0; 1 0 0; 0 0 1];
R76 = transpose(R67)
RA7 = transpose(R7A);

acc4 = RA7*R76*R64*R42*R20*R0G*[0;0;1];
