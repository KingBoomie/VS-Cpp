#include "stdafx.h" 
/* - these are under stdafx.h
#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <algorithm>
#include <thread>
#include <atomic> 
#include <cmath>
#include <windows.h>
#include <string>
#include <cstdio>
*/
#include "functions.h"
#include "euler.h"

using namespace std;

void getRand2(initializer_list<int> args){
	vector<int> nums = getRand(args.begin()[0], args.begin()[1], args.begin()[2], args.begin()[3]);
}

void printVec(vector<int> nums){
	for (auto i : nums){
		cout << i << " ";
	}
	cout << endl;
}

void printNums(initializer_list<int> args) {
	
	auto argsIt = args.begin();
	
	vector<int> nums = getRand(argsIt[0], argsIt[1], argsIt[2], argsIt[3]);

	for (auto i : nums){
		cout << i << "\n";
	}
}

vector<int> divisors(int num){
	vector<int> divs;
	for (int i = 1; i <= num; ++i){
		if (num % i == 0){
			divs.push_back(i);
		}
	}
	return divs;
}

int trianglenum(int count){
	int tri = 0;
	for (int i = 1; i <= count; ++i){
		tri += i;
	}
	return tri;
}

void problem12(){
	int i = 0;
	while (divisors(trianglenum(i)).size() < 500){
		i++;
	}
	cout << trianglenum(i);
}

pair<string, string> split(string str, char splitter){
	size_t split = str.find(splitter);
	return make_pair<string, string>(str.substr(0, splitter), str.substr(splitter));
}



int _tmain(int argc, _TCHAR* argv[])
{
	//thread clock(consoleclock);
	
	Sleep(100);

	int num_of_lines;
	cin >> num_of_lines;

	string dir;
	vector<string> lines(num_of_lines);
	for (auto &line : lines){
		cin >> line;
	}

	cin >> dir;

	cout << 
	

	//clock.join();
	return 0;
}

