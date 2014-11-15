function [ F ] = myFunctionRmod_1( x )

[acc1, acc2, acc3, acc4, joints] = readInput(0,900);
acc1_1 = Normalize(acc1);
J1_1 = joints(1,1);
J2_1 = joints(1,2);

[acc1, acc2, acc3, acc4, joints] = readInput(0,1500);
acc1_2 = Normalize(acc1);
J1_2 = joints(1,1);
J2_2 = joints(1,2);

[acc1, acc2, acc3, acc4, joints] = readInput(0,2500);
acc1_3 = Normalize(acc1);
J1_3 = joints(1,1);
J2_3 = joints(1,2);

[acc1, acc2, acc3, acc4, joints] = readInput(0,3500);
acc1_4 = Normalize(acc1);
J1_4 = joints(1,1);
J2_4 = joints(1,2);

[acc1, acc2, acc3, acc4, joints] = readInput(0,400);
acc1_5 = Normalize(acc1);
J1_5 = joints(1,1);
J2_5 = joints(1,2);

[acc1, acc2, acc3, acc4, joints] = readInput(0,2000);
acc1_6 = Normalize(acc1);
J1_6 = joints(1,1);
J2_6 = joints(1,2);

F = [abs(J1_1-predictJ1(acc1_1,x))+abs(transpose(x)*x-eye(3))+ abs(J2_1-predictJ2(acc1_1,x))+abs(transpose(x)*x-eye(3));
    abs(J1_2-predictJ1(acc1_2,x))+abs(transpose(x)*x-eye(3))+ abs(J2_2-predictJ2(acc1_2,x))+abs(transpose(x)*x-eye(3));
    abs(J1_3-predictJ1(acc1_3,x))+abs(transpose(x)*x-eye(3))+ abs(J2_3-predictJ2(acc1_3,x))+abs(transpose(x)*x-eye(3));
    abs(J1_4-predictJ1(acc1_4,x))+abs(transpose(x)*x-eye(3))+ abs(J2_4-predictJ2(acc1_4,x))+abs(transpose(x)*x-eye(3));
    abs(J1_5-predictJ1(acc1_5,x))+abs(transpose(x)*x-eye(3))+ abs(J2_5-predictJ2(acc1_5,x))+abs(transpose(x)*x-eye(3));
    abs(J1_6-predictJ1(acc1_6,x))+abs(transpose(x)*x-eye(3))+ abs(J2_6-predictJ2(acc1_6,x))+abs(transpose(x)*x-eye(3))];

end

