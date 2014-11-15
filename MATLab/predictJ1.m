function [ J1 ] = predictJ1( acc , Rmod )

        setGlobalAcc1(acc);
        setGlobalRmod(Rmod);

        % Algorithm Setup
        options = optimoptions('fsolve');%,'Display','iter');

        % Determine Joints One and Two
        x0 =[1,1];
        [x,fval] = fsolve(@myFunction12mod,x0,options);
        J1 = x(1,1);
        J2 = x(1,2);

end

