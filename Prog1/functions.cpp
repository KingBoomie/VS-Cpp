#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>
#include <Windows.h>
#include <string>
#include <cstdio>


std::vector<int> getRand(int count, const int min, const int max, int type = 0){
	//TODO: use templates
	std::vector<int> random_ints(count);

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(min, max);

		for (int i = 0; i < count; ++i){
		random_ints[i] = distribution(generator); // generate random int flat in [min, max]
	}
	if (type == 0){
		std::cout << "Random numbers returned" << std::endl;

	}
	else if (type == 1){
		sort(random_ints.begin(), random_ints.end());
		std::cout << "Random sorted ascending numbers returned" << std::endl;

	}
	else if (type == 2){
		sort(random_ints.begin(), random_ints.end(), [](int a, int b) { return b < a; });
		std::cout << "Random sorted descending numbers returned" << std::endl;
	}
	return random_ints;
}



float timer(void(*f)(std::initializer_list<int>), std::initializer_list<int> args){
	clock_t time = clock(); //get initial value of time

	(*f)(args); //execute function

	time = clock() - time;
	return (float)time / CLOCKS_PER_SEC;
}

float timer(void(*f)(std::vector<int>), std::vector<int> args){
	clock_t time = clock(); //get initial value of time

	(*f)(args); //execute function

	time = clock() - time;
	return (float)time / CLOCKS_PER_SEC;
}

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	localtime_s(&tstruct, &now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

// to print time to console
void consoleclock(){

	COORD      startcoord;
	HANDLE     console = GetStdHandle(STD_OUTPUT_HANDLE);

	startcoord.X = 0; startcoord.Y = 0;

	while (true)
	{
		
		CONSOLE_SCREEN_BUFFER_INFO consoleinfo = { 0 };
		
		GetConsoleScreenBufferInfo(console, &consoleinfo);
		COORD returncoord = consoleinfo.dwCursorPosition;
		//COORD returncoord;
		//returncoord.X = 0; returncoord.Y = 2;
		SetConsoleCursorPosition(console, startcoord); // moves to the coordinates
		
		std::cout << "The time is now: " << currentDateTime() << std::endl;

		SetConsoleCursorPosition(console, returncoord); // moves to the coordinates CX
		Sleep(1000);
	}
}