#include "stdafx.h"



std::vector<int> getRand(const int count, const int min, const int max, const int type = 0){
	//TODO: use templates

	std::vector<int> random_nums(count);

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(min, max);

	
	if (type == 0){ // random

		for (unsigned i = 0; i < count; ++i){
			random_nums[i] = distribution(generator); // generate random int flat in [min, max]
		}

		std::cout << "Random numbers returned" << std::endl;

	}
	else if (type == 1){ // ascending
		for (unsigned i = 0; i < count; ++i){
			random_nums[i] = distribution(generator); // generate random int flat in [min, max]
		}
		sort(random_nums.begin(), random_nums.end());
		std::cout << "Random sorted ascending numbers returned" << std::endl;

	}
	else if (type == 2){ // descending

		for (unsigned i = 0; i < count; ++i){
			random_nums[i] = distribution(generator); // generate random int flat in [min, max]
		}

		sort(random_nums.begin(), random_nums.end(), [](int a, int b) { return b < a; });
		std::cout << "Random sorted descending numbers returned" << std::endl;
	}
	else if (type == 3){ // ascending w/o duplicates

		for (unsigned i = 0; i < count; ++i){
			random_nums[i] = distribution(generator); // generate random int flat in [min, max]
		}

		do{
			while (random_nums.size() < count){
				random_nums.push_back(distribution(generator));
			}
			sort(random_nums.begin(), random_nums.end());
			auto end_unique = unique(random_nums.begin(), random_nums.end()); // where the uniques end and duplicates start
			random_nums.erase(end_unique, random_nums.end());

		} while (random_nums.size() < count);

	} 
	else if (type == 4){ // descending w/o duplicates
		for (int i = 0; i < count; ++i){
			random_nums[i] = distribution(generator); // generate random int flat in [min, max]
		}

		do{
			while (random_nums.size() < count){
				random_nums.push_back(distribution(generator));
			}
			sort(random_nums.begin(), random_nums.end(), [](int a, int b) { return b < a; });
			auto end_unique = unique(random_nums.begin(), random_nums.end()); // where the uniques end and duplicates start
			random_nums.erase(end_unique, random_nums.end());

		} while (random_nums.size() < count);

	}
	else if (type == 5){ // const
		fill(random_nums.begin(), random_nums.end(), distribution(generator));
	}
	
	return random_nums;
}

/*std::vector<float> getRand(const int count, const int min, const int max, int decimalPlaces = 3, const int type = 0){
	//TODO: use templates
	std::vector<float> random_nums(count);

	decimalPlaces = 10 ^ decimalPlaces; //turn var something stating a num(3) to actual size (1000)

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(min * decimalPlaces, max * decimalPlaces); 
	// raise the minimum and maximum, so the number could be in the correct size after division

	for (int i = 0; i < count; ++i){
		random_nums[i] = (float)distribution(generator) / decimalPlaces; 
		// divide the random num to artificially create a number with a comma
	}
	if (type == 0){
		std::cout << "Random numbers returned" << std::endl;

	}
	else if (type == 1){
		sort(random_nums.begin(), random_nums.end());
		std::cout << "Random sorted ascending numbers returned" << std::endl;

	}
	else if (type == 2){
		sort(random_nums.begin(), random_nums.end(), [](int a, int b) { return b < a; });
		std::cout << "Random sorted descending numbers returned" << std::endl;
	}
	return random_nums;
}*/



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
	strftime(buf, sizeof(buf), "%X", &tstruct); // "%Y-%m-%d.%X" for year-month-day aswell

	return buf;
}


// to print time to console
void consoleclock(){

	COORD textCoord;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleinfo = { 0 };
	std::string text;

	COORD startPos;
	startPos.X = 0; startPos.Y = 1;
	SetConsoleCursorPosition(console, startPos); // put the starting position on the second row, clock takes the first one

	textCoord.Y = 0;

	while (true)
	{
		text = currentDateTime();

		GetConsoleScreenBufferInfo(console, &consoleinfo);
		COORD returncoord = consoleinfo.dwCursorPosition; // old cursor pos

		textCoord.X = consoleinfo.dwMaximumWindowSize.X/2 - (text.size() + 1) / 2; // set x to the amount of space needed to center line

		SetConsoleCursorPosition(console, textCoord); // moves to the coordinates
		
		std::cout << text;

		SetConsoleCursorPosition(console, returncoord); // returns to original coordinates
		Sleep(1000);
	}
}