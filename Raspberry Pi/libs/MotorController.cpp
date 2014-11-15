
#define _USE_MATH_DEFINES

#include <cmath>
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
//#include "stringUtility.h"
#include "MotorController.h"

using namespace std;

#define PI 3.14159265
#define AtoR 0.0174532925
#define MAXENCODER 2147483647

string MotorController::motorLookup[] = {"H","A","B","C","D","E","F","G","H"};

string toString(long val){
    ostringstream stream;
	stream << val;
    return stream.str();
}

MotorController::MotorController()
{
	long int sum;
	initialized = false;
	connected = false;
	//controller = Galil("192.168.1.22");
	//motorLookup[] = {'H','A','B','C','D','E','F','G','H'};

	//calculate conversion values
	enc2Radian[1] = (2*PI)/13200000;//a
	enc2Radian[2] = (2*PI)/13320000;//b
	enc2Radian[3] = (2*PI)/4720000;//c
	enc2Radian[4] = (2*PI)/4720000;//d
	enc2Radian[5] = (2*PI)/3840000;//e
	enc2Radian[6] = (-2*PI)/4000000;//f
	enc2Radian[7] = (2*PI)/2880000; //g

	rad2Enc[0] = 0;
	rad2Enc[1] = 13200000/(2*PI);//a
	rad2Enc[2] = 13320000/(2*PI);//b
	rad2Enc[3] = 4720000/(2*PI);//c
	rad2Enc[4] = 4720000/(2*PI);//d
	rad2Enc[5] = 3840000/(2*PI);//e
	rad2Enc[6] = -4000000/(2*PI);//f
	rad2Enc[7] = 2880000/(2*PI); //g
	rad2Enc[8] = 0;

	sum = 6595000+5100000+1800000+2300000+2000000+2000000+1500000;
	normalize[1] = 6595000/sum;
	normalize[2] = 5100000/sum;
	normalize[3] = 1800000/sum;
	normalize[4] = 2300000/sum;
	normalize[5] = 2000000/sum;
	normalize[6] = 2000000/sum;
	normalize[7] = 1500000/sum;
	
	// Setting up Socket Communucation with Galil Board
	int cID, s = 0;

	// Initializing Socket Structs
	struct addrinfo host_info;
	struct addrinfo *host_info_list;

	// Setting host_info values to zeros
	memset(&host_info, 0, sizeof host_info);
	
	// Setting host type
	host_info.ai_family = AF_INET;
	host_info.ai_socktype = SOCK_STREAM;

	// Getting connection info from IP
	s = getaddrinfo("192.168.1.22", NULL, &host_info, &host_info_list);
	if(s != 0)
		cout << "IP error" << endl;
	

	// Setting up client(R-Pi) socket
	sID = socket(AF_INET, SOCK_STREAM, 0);
	cout << "Communication Socket ID: " << sID << endl;


	// Client(R-Pi) connecting to Server(Controller Board)
	cID = connect(sID, host_info_list->ai_addr, host_info_list->ai_addrlen);
	if(cID == 0)
	{
		cout << "WMRA Connection Success\n" << endl;
		connected = true;
	}
	else
		cout << "WMRA Connection Error\n" << endl;
	
	//read settings
	//call initialize();
	//set initilez flag
}
//MotorController::~MotorController()
//{
//	command("MO"); //turn off motors
//}
bool MotorController::initialize(){
	// set PID values

	// set motor types as in brushed motr etc..
	if(connected)
	{

		command("BRA=1\r");
		command("BRB=1\r");
		command("BRC=1\r");
		command("BRD=1\r");

		//set all motors to position tracking mode
		command("PTA=1\r");
		command("PTB=1\r");
		command("PTC=1\r");
		command("PTD=1\r");
		command("PTE=1\r");
		command("PTF=1\r");
		command("PTG=1\r");
		command("PTH=1\r");

		// set accelaration decelaration values
		//#debug CHANGE LATER TO PROPER ANGLES

		setAccel(1, 0.2);
		setAccel(2, 0.2);
		setAccel(3, 0.1);
		setAccel(4, 0.1);
		setAccel(5, 0.1);
		setAccel(6, 0.1);
		setAccel(7, 0.1);

		setDecel(1, 0.2);
		setDecel(2, 0.2);
		setDecel(3, 0.1);
		setDecel(4, 0.1);
		setDecel(5, 0.1);
		setDecel(6, 0.1);
		setDecel(7, 0.1);

		//set accelaration smoothing 
		command("IT*=0.6");	

		initialized = true;
	
		// ready position, #debug I believe this should be a function of its own, and the ready position should be recovered from the text file as well.
		definePosition(1, (PI/2));
		definePosition(2, (PI/2));
		definePosition(3, 0);
		definePosition(4, (PI/2));
		definePosition(5, (PI/2));
		definePosition(6, -(PI/3));
		definePosition(7, 0);
		definePosition(8, 0);

		command("SH"); //turn on motors
		initialized = true;
	}
	else
	{
		cout << "Error: No WMRA connection" << endl;
		initialized = false;
		return false;
	}
	return true;
}

bool MotorController::isInitialized() // return initialized
{
	return initialized;
}

bool MotorController::Stop() //emergancy stop
{
	command("ST ABCDEFGH");
	return true; // #debug does this return need to happen after the Arm has fully stopped?
}

bool MotorController::Stop(int motorNum) // emergancy stop a single motor
{

	if(isValidMotor(motorNum)){
		string motor = motorLookup[motorNum];
		command("ST " + motor);
		return true;
	}
	else{
		return false;
	}

}
bool MotorController::setPID(int motorNum, int P, int I, int D){
	return false;
}


float MotorController::readPos(int motorNum) // returns the current motor angle in radians
{
	if(isInitialized())
	{
		long encoderVal;	
		float angle;
		string result;
		string commmand_str;
		string motor;
		if ( isValidMotor(motorNum)){
			motor = motorLookup[motorNum];
			commmand_str = "TP" + motor;
			//cout << commmand_str << endl;
			result = command(commmand_str);
			result = command(commmand_str);
			//cout << result << endl;
			istringstream stream(result);
			stream >> encoderVal;
			angle = encToAng(motorNum, encoderVal);        
			//cout << "Read Encoder Value for Joint " << motorNum << " is " << encoderVal << endl;
			//cout << "Which is " << angle << " radians" << endl;
			return angle;
		}
		else{
			if(motorNum != 9 && motorNum != 10)
			{
				cerr << "The motor specified is not valid" << endl;
			}
		}
	}
	cout << "Error reading position" << endl;
	return 0.0;
}

float MotorController::readPosErr(int motorNum) // returns the error in  
{

	long encoderVal;	
	string result;
	string motor;
	if ( isValidMotor(motorNum)){
		motor = motorLookup[motorNum];
		result = command( "TE" + motor);	
		istringstream stream(result);
		stream >> encoderVal;
		return encToAng(motorNum, encoderVal);        
	}
	else{
		if(motorNum != 9 && motorNum != 10)
		{
			cerr << "The motor specified is not valid" << endl;
		}
	}
}

bool MotorController::setMaxVelocity(int motorNum, float angularVelocity) // SPA=100000
{
	if(isValidMotor(motorNum)){
		long encVal = abs(angToEnc(motorNum,angularVelocity));
		string motor = motorLookup[motorNum];
		if ((encVal >= 0) && (encVal < 12000000)){
			string command_str = "SP" + motor + "=" + toString(encVal);
			command(command_str);
			return true;            
		}
		else{
			cerr << "The velocity is outside the range" << endl;           
		}
	}
	else{
		if(motorNum != 9 && motorNum != 10)
		{
			cerr << "The motor specified is not valid" << endl;
		}
	}

}

bool MotorController::setAccel(int motorNum, float angularAccelaration)
{	
	if(isValidMotor(motorNum)){
		long encVal = abs(angToEnc(motorNum,angularAccelaration));
		string motor = motorLookup[motorNum];
		if ((encVal >= 1024) && (encVal <= 67107840)){
			string command_str = "AC" + motor + "=" + toString(encVal);
			command(command_str);
			return true;            
		}
		else{
			cerr << "The Accelaration is outside the range" << endl;          
		}
	}
	else{
		if(motorNum != 9 && motorNum != 10)
		{
			cerr << "The motor specified is not valid" << endl;
		}
	}

}

bool MotorController::setDecel(int motorNum, float angularDecelaration)
{
	if(isValidMotor(motorNum)){
		long encVal = abs(angToEnc(motorNum,angularDecelaration));
		string motor = motorLookup[motorNum];
		if ((encVal >= 1024) && (encVal <= 67107840)){
			string command_str = "DC" + motor + "=" + toString(encVal);
			command(command_str);
			return true;            
		}
		else{
			cerr << "The Decelaration is outside the range" << endl;           
		}
	}
	else{
		if(motorNum != 9 && motorNum != 10)
		{
			cerr << "The motor specified is not valid" << endl;
		}
	}

}

bool MotorController::definePosition(int motorNum,float angle)
{
	if(isInitialized())
	{
		if(isValidMotor(motorNum)){
			long encVal = angToEnc(motorNum,angle);
			
			//cout << "Define Encoder Value for Motor " << motorNum << " as " << encVal << endl;
			//cout << "Which is " << angle << " radians" << endl;
			string motor = motorLookup[motorNum];
			if ((encVal >= -2147483647) && (encVal <= 2147483648)){
				string command_str = "DP" + motor + "=" + toString(encVal);
				//cout << command_str << endl;
				command(command_str);
				return true;            
			}
			else{
				cerr << "The Position is outside the range" << endl;          
			}
		}
		else{
			if(motorNum != 9 && motorNum != 10)
			{
				cerr << "The motor specified is not valid" << endl;
			}
		}
	}
	cout << "Motor Controller not initialized or error occurred when setting position" << endl;
	return 0;
}

bool MotorController::positionControl(int motorNum,float angle)
{
	if(isInitialized())
	{
		if(isValidMotor(motorNum)){
			long encVal = (degToEnc(motorNum,angle));
			//cout << "enc_val = " << encVal << endl;
			string motor;
			motor = motorLookup[motorNum];
			long temp = abs(encVal);
			if (temp <= 2147483648){
				string command_str = "PA" + motor + "=" + toString(encVal);
				//cout << command_str << endl;
				try	{
					string ret = command(command_str);
					//cout << "ret = " << ret << endl;
				}
				catch(string s){
					cout << s << endl;
					cout << endl;
				}
				return true;            
			}
			else{
				cerr << "The Position is outside the range" << endl;           
			}
		}
		else{
			if(motorNum != 9 && motorNum != 10)
			{
				cerr << "The motor specified is not valid" << endl;
			}
		}
	}	
	cout << "Motor Controller not initialized or error occurred when setting position" << endl;
	return 0;
}

bool MotorController::MotorsOFF()
{
	command("MO"); //turn off motors
	return 1;
}

int MotorController::degToEnc(int motorNum, float deg) // #debug needs to be finished, Also need to check initialized
{
	long temp = deg * 0.0174532925 * rad2Enc[motorNum];
	if (motorNum < 9 && motorNum > 0){
		return temp;
	}
	else{
		cerr << "motor number outside range" << endl;
	}
	return 0;

}


/*------------------------------------------------------

Private Functions

------------------------------------------------------*/

inline bool MotorController::isValidMotor(int motorNum){
	if( motorNum >= 1 && motorNum <= 8) return true;
	else return false;
}

bool readSettings() // Returns 0 is no file found or error occured
{
	return true;

}

float MotorController::encToAng(int motorNum, long encCount) // #debug needs to be finished, Also need to check initialized
{
	if (motorNum < 9 && motorNum > 0){
		return encCount * enc2Radian[motorNum]; 
	}
	else{
		cerr << "motor number outside range" << endl;
	}
}

long MotorController::angToEnc(int motorNum, float encCount) // #debug needs to be finished, Also need to check initialized
{
	if (motorNum < 9 && motorNum > 0){
		return encCount * rad2Enc[motorNum]; 
	}
	else{
		cerr << "motor number outside range" << endl;
	}

}

long MotorController::J1_Encoder_Val(double J1angle, int quadrant)
{
	double trueAng;
	switch(quadrant)
	{
		case 0:
			trueAng = (90+J1angle);
			break;
		case 1:
			trueAng = (90+J1angle);
			break;
		case 2:
			trueAng = (90-J1angle);
			break;
		case 3:
			trueAng = (90-J1angle);
			break;
		case 4:
			trueAng = (90+J1angle);
			break;
		case 5:
			trueAng = (90+J1angle);
			break;
		case 6:
			trueAng = ((J1angle-90)*-1);
			break;
		case 7:
			trueAng = ((J1angle-90)*-1);
			break;
	}
	
	
}


//command() sends an ASCII Command (e.g. "TPX") to the controller and retrieves a Response (e.g. "123\r\n:").
//The size of Response should be supplied as ResponseSize so that unallocated memory is not overwritten.
//If you statically allocate your response buffer (e.g. char buff[100]) use sizeof(buff).
int MotorController::commandGalil(char* Command, char* Response, int ResponseSize) //returns the number of bytes read
{
   char acPartialResponse[512] = {0}; //buffer to contain partial responses (which will be concatenated together to form the final response)
   int iPartialBytesRead = 0; //number of bytes read each time through the loop
   int iTotalBytesRead = 0;   //the total number of bytes read.  Can't exceed ResponseSize.
   
   
   Response[0] = 0; //set response to null string 
   write(sID, Command, strlen(Command)); //write the command to the controller
   //write(sID, "\r", 1);

   //keep reading until we (a) get a colon (b) get a question mark (c) fill up the callers Response buffer
   while(1)
   {
      iPartialBytesRead = read(sID, acPartialResponse, sizeof(acPartialResponse)); //read some characters
      
      if(iPartialBytesRead <= 0)   //nothing read, keep reading until :
         continue;
      else if(iTotalBytesRead + iPartialBytesRead > ResponseSize) //get out of the loop if we will fill up the caller's buffer, iPartialBytesRead >= 1
         break;
      else 
      {
         strncat(Response, acPartialResponse, iPartialBytesRead); //add the partial response to the full response.  Response is null terminated
         iTotalBytesRead += iPartialBytesRead; //tally up the total number of bytes read
   //    printf("%s|%s|%i\n", Response, acPartialResponse, iPartialBytesRead); 
         if (acPartialResponse[iPartialBytesRead - 1] == ':' || acPartialResponse[iPartialBytesRead - 1] == '?') //got a colon, iPartialBytesRead >= 1
            break;
      }
   }
   
   return(iTotalBytesRead);
}

string MotorController::command(string Command)
{
	char com[300];
	char ret[300];
	string c = Command + "\r";
	strcpy(com, c.c_str());
	//cout << com << endl;
	commandGalil(com, ret, sizeof(ret));
	string ret_str(ret);
	return ret_str;
}

