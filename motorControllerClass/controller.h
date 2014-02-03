#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#define _USE_MATH_DEFINES

#include <cmath>
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

class client_tcpsocket;

class controller {
public:
	controller();
	~controller();
	intialize();
	string command(string Command);
	
private:
	client_tcpsocket sock;
};
	

#endif;