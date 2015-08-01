#pragma once
#include <string>
#include <inttypes.h>

#include "asio-1.10.4/asyncSerial/AsyncSerial.h"

class Wheel
{
public:

	  //************************************
	  // Parameter: char label = the number part of wheel id
	  // Example usage: 
	  //	Wheel wheelA(2); 
	  //	wheelA.setSpeed(100);
	  //************************************
	  Wheel(uint8_t label);
	  ~Wheel();

	  int movement_from_last_call();
	  void setSpeed(short newSpeed);
private:
	  CallbackAsyncSerial serialconnection;

	  // Bind the correct wheel to serial_connection
	  void find_and_bind_wheel(unsigned char label);
	  uint8_t id;
};

