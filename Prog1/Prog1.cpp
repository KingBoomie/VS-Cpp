#include "stdafx.h"
#include "functions.h"

using namespace std;

void getRand2(initializer_list<int> args){
	vector<int> nums = getRand(args.begin()[0], args.begin()[1], args.begin()[2], args.begin()[3]);
}

void sqrttest(vector<int> nums){
	for (auto i : nums){
		sqrt(i);
	}
}

void sintest(vector<int> nums){
	for (auto i : nums){
		atan2(i, i*2);
	}
}


void printNums(initializer_list<int> args) {
	
	vector<int> nums = getRand(args.begin()[0], args.begin()[1], args.begin()[2], args.begin()[3]);

	for (auto i : nums){
		cout << i << "\n";
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	thread clock(consoleclock);
	
	
	

	clock.join();
	return 0;
}

