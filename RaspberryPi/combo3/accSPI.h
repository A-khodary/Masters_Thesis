/* accelerometer.h */
#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <bcm2835.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

class Accelerometer{
public:
	Accelerometer(int devNum);
	~Accelerometer();
	int rawData(int &_X, int &_Y, int &_z);
	int data(double &_X, double &_Y, double &_Z);

private:
	int type,initialized;

};

#endif