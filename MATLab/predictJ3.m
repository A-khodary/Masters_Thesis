function [ J3 ] = predictJ3(j1, j2, acc , Rmod )

        setGlobalAcc2(acc);
        setGlobalRmod(Rmod);
        setGlobalJ1(j1);
        setGlobalJ2(j2);
        
        % Algorithm Setup
        options = optimoptions('fsolve');

        % Determine Joints One and Two
        x0 =[0,1.5];
        [x,fval] = fsolve(@myFunction34mod,x0,options);
        J3 = x(1,1);
        J4 = x(1,2);

end

