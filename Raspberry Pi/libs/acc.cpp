/* accelerometer.c */
#include "acc.h"

using namespace std;

Acc::Acc()
{
	end = 0;
	dev = 0;
	initialized = false;
}

void Acc::normalize(double &_X, double &_Y, double &_Z)
{
	float V = sqrt((_X*_X)+(_Y*_Y)+(_Z*_Z));
	_X = _X/V;
	_Y = _Y/V;
	_Z = _Z/V;
}

int Acc::initialize(int devNum)
{
	dev = devNum;
	
	if(dev==1)
	{
		if(!bcm2835_init()) //Make sure bcm2835 is initialized
		{
			cout << "Failed to Initialize bcm2835" << endl;
			return 0;
		}
		else
			cout << "bcm2835 Initialized - 1" << endl;
		
		char buf[] = {0x00,0x00};
		bcm2835_spi_begin();
		bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
		bcm2835_spi_setDataMode(BCM2835_SPI_MODE3);                   // The default
		bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_64);    // The default
		bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
		bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default
		

		// POWER_CTL - Places device into standby mode
		buf[0] = 0x2D;
		buf[1] = 0x00;
		bcm2835_spi_transfern(buf, sizeof(buf));
sleep(0.1);
		// DATA_FORMAT - SPI set to 4-wire mode, G Range set to +-2g, Set to 10-bit mode
		buf[0] = 0x31;
		buf[1] = 0x00;
		bcm2835_spi_transfern(buf, sizeof(buf));
sleep(0.1);		
		// FIFO_CTL - Setting stream mode
		buf[0] = 0x38;
		buf[1] = 0x80;
		bcm2835_spi_transfern(buf, sizeof(buf));
sleep(0.1);		
		// POWER_CTL - Places device into measurement mode
		buf[0] = 0x2D;
		buf[1] = 0x08;
		bcm2835_spi_transfern(buf, sizeof(buf));
		
sleep(1);	
		
	}
	else if(dev==2)
	{
		if(!bcm2835_init()) //Make sure bcm2835 is initialized
		{
			cout << "Failed to Initialize bcm2835" << endl;
			return 0;
		}
		else
			cout << "bcm2835 Initialized - 2" << endl;
		
		char buf[] = {0x00,0x00};
		bcm2835_spi_begin();
		bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
		bcm2835_spi_setDataMode(BCM2835_SPI_MODE3);                   // The default
		bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_64);    // The default
		bcm2835_spi_chipSelect(BCM2835_SPI_CS1);                      // The default
		bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS1, LOW);      // the default

		// POWER_CTL - Places device into standby mode
		buf[0] = 0x2D;
		buf[1] = 0x00;
		bcm2835_spi_transfern(buf, sizeof(buf));
sleep(0.1);
		// DATA_FORMAT - SPI set to 4-wire mode, G Range set to +-2g, Set to 10-bit mode
		buf[0] = 0x31;
		buf[1] = 0x00;
		bcm2835_spi_transfern(buf, sizeof(buf));
sleep(0.1);		
		// FIFO_CTL - Setting stream mode
		buf[0] = 0x38;
		buf[1] = 0x80;
		bcm2835_spi_transfern(buf, sizeof(buf));
sleep(0.1);		
		// POWER_CTL - Places device into measurement mode
		buf[0] = 0x2D;
		buf[1] = 0x08;
		bcm2835_spi_transfern(buf, sizeof(buf));
		
		sleep(1);
	}
	else if(dev==3)
	{
		wiringPiSetup();
		int ID;
		ID = 0x1d;
		if((fd_I2C=wiringPiI2CSetup(ID))<0)
			printf("error opening i2c channel\n");
		else
			printf("i2c channel open - 3\n");
		
		wiringPiI2CWriteReg8(fd_I2C,45,0);
		sleep(0.1);
		wiringPiI2CWriteReg8(fd_I2C,49,0); 
		sleep(0.1);
		wiringPiI2CWriteReg8(fd_I2C,45,8);
		sleep(0.1);
	}
	else if(dev==4)
	{
		wiringPiSetup();
		int ID = 0x53;
		if((fd_I2C=wiringPiI2CSetup(ID))<0)
			printf("error opening i2c channel\n");
		else
			printf("i2c channel open - 4\n");
		
		wiringPiI2CWriteReg8(fd_I2C,45,0);
		sleep(0.1);
		wiringPiI2CWriteReg8(fd_I2C,49,0); 
		sleep(0.1);
		wiringPiI2CWriteReg8(fd_I2C,45,8);
		sleep(0.1);
	}

	initialized = 1;
}

Acc::~Acc()
{
		bcm2835_spi_end();
}
	
int Acc::data_raw(int &_X, int &_Y, int &_Z)
{
	int X,Y,Z, X_temp,Y_temp,Z_temp;
	X_temp = 0;
	Y_temp = 0;
	Z_temp = 0;
	int setSize = 10;
	int OUT_FLAG = 1;
	while(OUT_FLAG)
	{
		X_temp = 0;
		Y_temp = 0;
		Z_temp = 0;
		for(int i = 0; i < setSize; i++)
		{
			//sleep(0.01);
			char values[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; // Read X,Y,Z
			
			if(dev==3 || dev==4)
			{
				if((fd_I2C)>=0)
				{
					values[0] = wiringPiI2CReadReg8(fd_I2C,0x32);
					values[1] = wiringPiI2CReadReg8(fd_I2C,0x33);
					values[2] = wiringPiI2CReadReg8(fd_I2C,0x34);
					values[3] = wiringPiI2CReadReg8(fd_I2C,0x35);
					values[4] = wiringPiI2CReadReg8(fd_I2C,0x36);
					values[5] = wiringPiI2CReadReg8(fd_I2C,0x37);
				}
			}

			else if(dev==1)
			{
				bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
				sleep(0.1);
				bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default
				sleep(0.1);
				
				char buf[] = {0xF2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; // Read X,Y,Z
				bcm2835_spi_transfern(buf,sizeof(buf));
				for(int i = 0; i < 6; i++)
				{
					values[i] = buf[i+1];
				}
			}
			else if(dev==2)
			{
				bcm2835_spi_chipSelect(BCM2835_SPI_CS1);                      // The default
				sleep(0.1);
				bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS1, LOW);      // the default
				sleep(0.1);
				
				char buf[] = {0xF2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; // Read X,Y,Z
				bcm2835_spi_transfern(buf,sizeof(buf));
				for(int i = 0; i < 6; i++)
				{
					values[i] = buf[i+1];
				}
			}
			
			
			X = values[1] << 8 | values[0];
			if(X >= 32768)
			{
				X = X ^ 0xFFFF;
				X = X+1;
				X = X*-1;
			}

			Y = values[3] << 8 | values[2];
			if(Y >= 32768)
			{
				Y = Y ^ 0xFFFF;
				Y = Y+1;
				Y = Y*-1;
			}
			
			Z = values[5] << 8 | values[4];
			if(Z >= 32768)
			{
				Z = Z ^ 0xFFFF;
				Z = Z+1;
				Z = Z*-1;
			}			
		}
		if (X>300 || X <-300 || Y>300 || Y <-300 || Z>300 || Z<-300 || X==-1 || Y==-1 || Z==-1 || X==0 || Y==0 || Z==0)
		{
			std::cout << "BAD DATA READ, X: " << Z << "\tY: " << Y << "\tZ: " << Z << std::endl;		
		}
		else
		{
			OUT_FLAG = 0;
		}
		
		//acc_raw.resize(3);
		//acc_raw[0] = X_temp/setSize;
		//acc_raw[1] = Y_temp/setSize;
		//acc_raw[2] = Z_temp/setSize;
	}
	//_X = acc_raw[0];
	//_Y = acc_raw[1];
	//_Z = acc_raw[2];
	
	_X = X;
	_Y = Y;
	_Z = Z;
	return 1;
}

int Acc::data(double &_X, double &_Y, double &_Z)
{
	int X,Y,Z;
	double gains;
	
	// scale = (4/1024) = 0.0039;
	gains = 0.0039; 
	
	if(!data_raw(X, Y, Z))
		return 0;
	
	double x = (double)X;
	double y = (double)Y;
	double z = (double)Z;
	
	normalize(x, y, z);
	float sumxyz = sqrt(x*x+y*y+z*z);
	
	if(sumxyz > 1.01 || sumxyz < 0.98) 
	{
		cout << "X: " << x << "\tY: " << y << "\tZ: " << z << "\tSum: " << sumxyz << endl;
		cout << "\n\tError: Normalization Failed, Norm value: " << sumxyz << "\n" << endl;
	}
	
	// Rotation around x
	double temp_p = sqrt((y*y)+(z*z));
	_X = atan2(x,temp_p);  // Radians
	
	// Rotation around y
	double temp_r = sqrt((x*x)+(z*z));
	_Y = atan2(y,temp_r);  // Radians
	
	// Rotation around z
	double temp_y = sqrt((x*x)+(y*y));
	_Z = atan2(temp_y,z);  // Radians
	
	acc.resize(3);
	acc[0] = _X;
	acc[1] = _Y;
	acc[2] = _Z;
	
	return 1;
}

int Acc::isInitialized()
{
	return initialized;
}