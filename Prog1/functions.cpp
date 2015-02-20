#include "stdafx.h"



std::vector<int> getRand(const unsigned count, const int min, const int max, const int type = 0){
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
		for (unsigned i = 0; i < count; ++i){
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

long long power(int num, unsigned int power){

	if (num == 2) {
		return 1 << power;
	}

	if (power == 1){
		return num;
	}
	else if (power % 2 == 0){
		return pow(num * num, power / 2);
	}
	else{ // If not even, then mutilpy num separately
		return num * pow(num * num, power / 2);
	}
}

template<typename T>
bool checkPrime(T num){

	if (num == 1) return true;
	if (num == 2) return true;
	if (num % 2 == 0) return false;

	std::vector<T> primes = primeSundaram(sqrt(num));

	for (auto prime : primes){
		if (num % prime == 0){
			return false;
		}
	}

	return true;
}

/*
template <typename T, typename A>
std::vector<T, A> primeSundaram(T max){ // http://en.wikipedia.org/wiki/Sieve_of_Sundaram

	max /= 2; // This will output all nums 2xMax + 1, so max needs to be 2 times smaller

	vector<T, A> primes;
	vector<bool> toDelete(max, false);

	for (int j = 1; j * 2 < max; ++j){
		for (int i = 1; i * 2 < max; ++i){
			if (i + j + 2 * i * j >= max){
				break;
			}
			toDelete[i + j + 2 * i*j] = true;
		}
	}

	for (int i = 3; i < max; ++i){
		if (toDelete[i]){
			continue;
		}
		else{
			primes.push_back(i * 2 + 1);
		}
	}

	return primes;
}
*/
std::vector<int> primeSundaram (int max) { // http://en.wikipedia.org/wiki/Sieve_of_Sundaram

	max /= 2; // This will output all nums 2xMax + 1, so max needs to be 2 times smaller

	std::vector<int> primes;
	std::vector<bool> toDelete (max, false);

	primes.push_back (2);
	primes.push_back (3);
	primes.push_back (5);

	for (int j = 1; j * 2 < max; ++j) {
		for (int i = 1; i * 2 < max; ++i) {
			if (i + j + 2 * i * j >= max) {
				break;
			}
			toDelete[i + j + 2 * i*j] = true;
		}
	}

	for (int i = 3; i < max; ++i) {
		if (toDelete[i]) {
			continue;
		} else {
			primes.push_back (i * 2 + 1);
		}
	}

	return primes;
}

////////////////////////////////////////////////////////
//					Misc funtions
////////////////////////////////////////////////////////

float timer(std::function<void()> f){
	clock_t time = clock(); //get initial value of time

	f(); //execute function

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


	while (!GetAsyncKeyState(0x46))
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
