function [ acc4 ] = findAcc4( j1, j2, j3, j4, j5, j6, j7 )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

%RG0 = [1 0 0; 0 1 0; 0 0 1];
R0G = getGlobalR0G;
R01 = [cos(j1) -sin(j1) 0; 0 0 1; -sin(j1) -cos(j1) 0];
R12 = [cos(j2) -sin(j2) 0; 0 0 -1; sin(j2) cos(j2) 0];
R02 = R01 * R12;
R20 = transpose(R02);
%R0G = transpose(RG0);

R23 = [cos(j3) -sin(j3) 0; 0 0 1; -sin(j3) -cos(j3) 0];
R34 = [cos(j4) -sin(j4) 0; 0 0 -1; sin(j4) cos(j4) 0];
R24 = R23 * R34;
R42 = transpose(R24);

R45 = [cos(j5) -sin(j5) 0; 0 0 1; -sin(j5) -cos(j5) 0];
R56 = [cos(j6) -sin(j6) 0; 0 0 -1; sin(j6) cos(j6) 0];
R46 = R45 * R56;
R64 = transpose(R46);

R67 = [cos(j7) -sin(j7) 0; 0 0 1; -sin(j7) -cos(j7) 0];
R7A = [0 -1 0; 1 0 0; 0 0 1];

R76 = transpose(R67);
RA7 = transpose(R7A);

RAG = RA7*R76*R64*R42*R20*R0G;

acc4 = RAG*[0;0;1];

end

