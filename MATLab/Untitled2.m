%test

syms j1 j2

R0G = getGlobalR0G;
RG0 = [1 0 0; 0 1 0; 0 0 1];
R0G = transpose(RG0);
R01 = [cos(j1) -sin(j1) 0; 0 0 1; -sin(j1) -cos(j1) 0];
R12 = [cos(j2) -sin(j2) 0; 0 0 -1; sin(j2) cos(j2) 0];
R02 = R01 * R12;
R2A = [0 0 -1 ; 1 0 0; 0 -1 0];

R20 = transpose(R02);
RA2 = transpose(R2A);
RAG = RA2*R20*R0G;
acc1 = RAG*[0;0;1]