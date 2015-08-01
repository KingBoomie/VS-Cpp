#pragma once
#include <unordered_map>
#include <iostream>

#include "config.h"
#include "asio-1.10.4/asyncSerial/AsyncSerial.h"
#include <system_error>
class PortScanner
{
private:
	  std::unordered_map<uint8_t, CallbackAsyncSerial> port_locations;

#ifdef _WIN32
	  std::string prefix = "COM";
#else
	  std::string prefix = "/dev/ttyACM";
#endif

public:


	  PortScanner(uint_fast8_t max_ports) {

			
			for (uint_fast8_t current_port = 0; current_port <= max_ports; ++current_port) 
			{
				  std::string serialname = prefix + std::to_string(current_port);
				  CallbackAsyncSerial temp_serial;

				  try {
						temp_serial.open(serialname, config::baudrate);
				  } catch (std::system_error& e) {
						// do nothing
				  } catch (std::exception& e) {
						std::cerr << "fail: find_and_bind_wheel \n\t " << e.what() << '\n';
				  }
			}
	  
	  }

	  ~PortScanner() {}
	  CallbackAsyncSerial getSerial(uint8_t label) {
			return port_locations[label];
	  }

};

