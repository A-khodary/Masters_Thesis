
#include "accI2C.h"

AccelerometerI2C::AccelerometerI2C(int devNum)
{	
	wiringPiSetup();
	int ID;
	switch(devNum) {
		case 1:
		{
			ID = 0x1d;
			if((fd_I2C=wiringPiI2CSetup(ID))<0)
				printf("error opening i2c channel\n");
			
			wiringPiI2CWriteReg8(fd_I2C,45,0);
			wiringPiI2CWriteReg8(fd_I2C,49,0); 
			wiringPiI2CWriteReg8(fd_I2C,45,8);
			break;
		}
		case 2:
		{
			ID = 0x53;
			if((fd_I2C=wiringPiI2CSetup(ID))<0)
				printf("error opening i2c channel\n");
			
			wiringPiI2CWriteReg8(fd_I2C,45,0);
			wiringPiI2CWriteReg8(fd_I2C,49,0); 
			wiringPiI2CWriteReg8(fd_I2C,45,8);
			break;
		}
		default:
			cout << "Device Number Not Valid" << endl;
	}
	initialized = true;
}


bool AccelerometerI2C::data_raw(int &_x, int &_y, int &_z)
{
	int xHigh,xLow,yHigh, yLow, zHigh, zLow, X, Y, Z;
	
	if((fd_I2C)>=0)
	{
		xLow = wiringPiI2CReadReg8(fd_I2C,50);
		xHigh = wiringPiI2CReadReg8(fd_I2C,51);
		yLow = wiringPiI2CReadReg8(fd_I2C,52);
		yHigh = wiringPiI2CReadReg8(fd_I2C,53);
		zLow = wiringPiI2CReadReg8(fd_I2C,54);
		zHigh = wiringPiI2CReadReg8(fd_I2C,55);
	}
	else
	{
		cout << "Error: Cannot Recieve Data" << endl;
		return 0;
	}

	X = xHigh << 8 | xLow;
	if(X >= 32768)
	{
		X = X ^ 0xFFFF;
		X = X+1;
		X = X*-1;
	}

	Y = yHigh << 8 | yLow;
	if(Y >= 32768)
	{
		Y = Y ^ 0xFFFF;
		Y = Y+1;
		Y = Y*-1;
	}

	Z = zHigh << 8 | zLow;
	if(Z >= 32768)
	{
		Z = Z ^ 0xFFFF;
		Z = Z+1;
		Z = Z*-1;
	}

	_x = X;
	_y = Y;
	_z = Z;
	
	return 1;
}

bool AccelerometerI2C::data(double &_x, double &_y, double &_z)
{
	int x,y,z;
	double X,Y,Z;
	if(!data_raw(x, y, z))
		return 0;
	
	double gain = 0.0039;    // scale = (4/1024) = 0.0039;
	X = (double)x * gain;
	Y = (double)y * gain;
	Z = (double)z * gain;
	
	// Rotation around X
	double temp_p = sqrt((Y*Y)+(Z*Z));
	_x = atan2(X,temp_p);  // Radians
	
	// Rotation around Y
	double temp_r = sqrt((X*X)+(Z*Z));
	_y = atan2(Y,temp_r);  // Radians
	
	// Rotation around Z
	double temp_y = sqrt((X*X)+(Y*Y));
	_z = atan2(Z,temp_y);  // Radians
	
	return 1;
}

bool AccelerometerI2C::isInitialized()
{
	return initialized;
}