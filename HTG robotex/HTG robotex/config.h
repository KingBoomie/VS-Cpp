#pragma once
#include <array>

namespace config {

	typedef struct {
		int id; // Motors will be 0, 1, 2
		double orientation; // in unit vectors
	} motor_info;

	//TODO: add actual orientations to motors (-1/sqrt(12) and so on...)
	static motor_info motor0{ 0, 0.0 };
	static motor_info motor1{ 1, 0.0 };
	static motor_info motor2{ 2, 0.0 };

	static const int camera_refresh_rate = 30;	  // in Frames Per Second
	static const int coilgun_max_power = 32000;  // Percentages of coilgun power

	// Connection data
	static const unsigned int baudrate = 115200;
	/** All others are default and unnecessary
	const int parity = 0;	  // none
	const int csize = 8;
	const int flowcontrol = 0; //none
	const int stopbits = 1;
	*/
	
	

#ifdef _WIN32 // Windows specific data


#elif // Not windows aka Linux
	std::array<std::string, 25> comports = {{
			"/dev/ttyACM0", "/dev/ttyACM1", "/dev/ttyACM2", "/dev/ttyACM3",  // Changed S0 to ACM2, S1 to ACM3
			"/dev/ttyACM5", "/dev/ttyACM5", "/dev/ttyACM6", "/dev/ttyACM7",
			"/dev/ttyS6", "/dev/ttyS7", "/dev/ttyS8", "/dev/ttyS9",
			"/dev/ttyS10", "/dev/ttyS11", "/dev/ttyS12", "/dev/ttyS13",
			"/dev/ttyS14", "/dev/ttyS15", "/dev/ttyUSB0", "/dev/ttyUSB1",
			"/dev/ttyUSB2", "/dev/ttyUSB3", "/dev/ttyUSB4", "/dev/ttyUSB5",
			"/dev/ttyAMA0", "/dev/ttyAMA1", "/dev/rfcomm0", "/dev/rfcomm1",
			}};

#endif // _WIN32
	
};



