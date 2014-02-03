
#include "SockStream.h"
#include "controller.h"

using namespace std;

client_tcpsocket controller::sock;

controller::controller()
{
	sock.open("192.168.1.106",23);
}
controller::~controller()
{

}

controller::intialize()
{

}

string controller::command(string Command)
{
	char com[300];
	char ret[300];
	string c = Command + "\r";
	strcpy(com, c.c_str());
	char acPartialResponse[512] = {0}; //buffer to contain partial responses (which will be concatenated together to form the final response)
	int iPartialBytesRead = 0; //number of bytes read each time through the loop
	int iTotalBytesRead = 0;   //the total number of bytes read.  Can't exceed ResponseSize.
   
	Response[0] = 0; //set response to null string 
	sock.write(Command, strlen(Command)); //write the command to the controller
	
	//keep reading until we (a) get a colon (b) get a question mark (c) fill up the callers Response buffer
	while(1)
	{
		iPartialBytesRead = sock.read(acPartialResponse, sizeof(acPartialResponse)); //read some characters
      
		if(iPartialBytesRead <= 0)   //nothing read, keep reading until :
			continue;
		else if(iTotalBytesRead + iPartialBytesRead > ResponseSize) //get out of the loop if we will fill up the caller's buffer, iPartialBytesRead >= 1
			break;
		else 
		{
			strncat(Response, acPartialResponse, iPartialBytesRead); //add the partial response to the full response.  Response is null terminated
			iTotalBytesRead += iPartialBytesRead; //tally up the total number of bytes read
			if (acPartialResponse[iPartialBytesRead - 1] == ':' || acPartialResponse[iPartialBytesRead - 1] == '?') //got a colon, iPartialBytesRead >= 1
				break;
		}
	}
   
	string ret_str(ret);
	return ret_str;
}