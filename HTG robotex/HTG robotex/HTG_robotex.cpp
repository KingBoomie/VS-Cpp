#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <functional>
#include <chrono>
#include <vector>


#include "config.h"
#ifdef _WIN32
	  #define _WIN32_WINNT 0x0602
#endif //_WIN32

#include "asio-1.10.4/asyncSerial/AsyncSerial.h"
#include "PortScanner.h"


int main () {

	//TODO: concurrently bind USB ports to motor objects
	//TODO: create motor class
	
	  PortScanner portscanner(25);

	  std::cout << portscanner.getSerial(4).isOpen() << '\n';
	  return 0;
}