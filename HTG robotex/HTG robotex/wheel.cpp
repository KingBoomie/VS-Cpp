#include <inttypes.h>
#include <iostream>
#include <system_error>

#include "wheel.h"
#include "config.h"
#include "asio-1.10.4/asyncSerial/AsyncSerial.h"

Wheel::Wheel(uint8_t label) {
	  
}


Wheel::~Wheel() {}


// Returns the movement of the wheel that has happened between 2 calls of this function
int Wheel::movement_from_last_call() {
	  return 0;
}


void Wheel::setSpeed(short newSpeed) {}


// Bind the correct wheel to serial_connection
void Wheel::find_and_bind_wheel(unsigned char label) {
	  
#ifdef _WIN32

	  // Limit the ports to 25
	  uint8_t current_port = 0;
	  while (current_port <= 25) {
			std::string serialname = "COM" + current_port;
			CallbackAsyncSerial temp_serial;

			try {
				  temp_serial.open(serialname, config::baudrate);
			} catch (std::system_error& e) {
				  std::cerr << "fail: find_and_bind_wheel \n\terrorcode: " << e.code() << "\n\t error: " << e.what() << '\n';
			}
	  }
#endif // _WIN32
}
