#pragma once
#include <array>

class config {
public:
	struct motor_info {
		int id; // Motors will be 0, 1, 2
		double orientation; // in unit vectors
		motor_info (int _id, double _orientation) : id(_id), orientation(_orientation) {}
	};
	//TODO: add actual orientations to motors (-1/sqrt(12) and so on...)
	motor_info motor0 { 0, 0.0 };
	motor_info motor1 { 1, 0.0 };
	motor_info motor2 { 2, 0.0 };

	const int camera_refresh_rate = 30; // in Frames Per Second
	const int coilgun_max_power = 32000; // Percentages of coilgun power
	
	

#ifdef _WIN32 // Windows specific data
	const std::array<std::string, 20> comports = std::array<std::string, 20>{
			"\\\\.\\COM1", "\\\\.\\COM2", "\\\\.\\COM3", "\\\\.\\COM4",
			"\\\\.\\COM5", "\\\\.\\COM6", "\\\\.\\COM7", "\\\\.\\COM8",
			"\\\\.\\COM9", "\\\\.\\COM10", "\\\\.\\COM11", "\\\\.\\COM12",
			"\\\\.\\COM13", "\\\\.\\COM14", "\\\\.\\COM15", "\\\\.\\COM16",
			"\\\\.\\COM17", "\\\\.\\COM18", "\\\\.\\COM19", "\\\\.\\COM20" 
		} ;


#elif // Not windows aka linux
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

