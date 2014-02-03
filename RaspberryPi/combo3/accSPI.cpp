/* accelerometer.c */
#include "accSPI.h"

using namespace std;

Accelerometer::Accelerometer(int devNum)
{
	if(!bcm2835_init()) /*Make sure bcm2835 is initialized*/
	{
		cout << "Failed to Initialize bcm2835" << endl;
		return;
	}
	
	char buf[] = {0x00,0x00};
	
	if(devNum==3)
	{
		bcm2835_spi_begin();
		bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
		bcm2835_spi_setDataMode(BCM2835_SPI_MODE3);                   // The default
		bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_64);    // The default
		bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
		bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default
		
		buf[0] = 0x2D;
		buf[1] = 0x00;
		bcm2835_spi_transfern(buf, sizeof(buf));
		buf[0] = 0x31;
		buf[1] = 0x00;
		bcm2835_spi_transfern(buf, sizeof(buf));
		buf[0] = 0x2D;
		buf[1] = 0x08;
		bcm2835_spi_transfern(buf, sizeof(buf));
	}
	else if(devNum==4)
	{
		bcm2835_spi_begin();
		bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
		bcm2835_spi_setDataMode(BCM2835_SPI_MODE3);                   // The default
		bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_64);    // The default
		bcm2835_spi_chipSelect(BCM2835_SPI_CS1);                      // The default
		bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS1, LOW);      // the default
		
		buf[0] = 0x2D;
		buf[1] = 0x00;
		bcm2835_spi_transfern(buf, sizeof(buf));
		buf[0] = 0x31;
		buf[1] = 0x00;
		bcm2835_spi_transfern(buf, sizeof(buf));
		buf[0] = 0x2D;
		buf[1] = 0x08;
		bcm2835_spi_transfern(buf, sizeof(buf));
	}
	else
	{
		cout << "spi error" <<endl;
	}

	initialized = 1;
}

Accelerometer::~Accelerometer()
{
		bcm2835_spi_end();
}
	
int Accelerometer::rawData(int &_X, int &_Y, int &_Z)
{
	int X,Y,Z;
	
	char values[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; // Read X,Y,Z

		char buf[] = {0xF2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; // Read X,Y,Z
	    bcm2835_spi_transfern(buf,sizeof(buf));
		for(int i = 0; i < 6; i++)
		{
			values[i] = buf[i+1];
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
	
	_X = X;
	_Y = Y;
	_Z = Z;
	return 1;
}

int Accelerometer::data(double &_X, double &_Y, double &_Z)
{
	int X,Y,Z;
	double gains[3];
	
	// scale = (4/1024) = 0.0039;
	gains[0] = 0.0039; 
	gains[1] = 0.0039; 
	gains[2] = 0.0039; 
	
	if(!Accelerometer::rawData(X, Y, Z))
		return 0;
	//cout  << "\tVALUES X: " << float(X)*gains[0] << "\tY: " << Y << "\tZ: " << Z << endl;
	
	double x = X * gains[0];
	double y = Y * gains[1];
	double z = Z * gains[2];
	// Rotation around x
	double temp_p = sqrt((y*y)+(z*z));
	_X = atan2(x,temp_p);  // Radians
	
	// Rotation around y
	double temp_r = sqrt((x*x)+(z*z));
	_Y = atan2(y,temp_r);  // Radians
	
	// Rotation around z
	double temp_y = sqrt((x*x)+(y*y));
	_Z = atan2(z,temp_y);  // Radians
	
	return 1;
}