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

int _tmain(int argc, _TCHAR* argv[])
{
	//thread clock(consoleclock);
	
	Sleep(100);

	cout << "Time taken: " << timer(getRand2, { 10000, 1, 1000000, 1}) << " seconds\n";
	cout << "Time taken: " << timer(getRand2, { 10000, 1, 1000000, 3 }) << " seconds\n";
	cout << "Time taken: " << timer(getRand2, { 10000, 1, 1000000, 4 }) << " seconds\n";
	cout << "Time taken: " << timer(getRand2, { 10000, 1, 1000000, 0 }) << " seconds\n";
	cout << "Time taken: " << timer(getRand2, { 10000, 1, 1000000, 5 }) << " seconds\n";
	/*vector <int> input;
	vector <vector <int> > allInput;

	string temp = "notempty";

	while (temp.size() != 0){
		getline(cin, temp);
		cout << temp << endl;
		
		for (int i = 0; i < 9; ++i){
			input.push_back((int)temp.at(i));
		}
		allInput.push_back(input);
	}

	for (auto i : allInput){
		for (auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}

	cout << "finised input";
	//----------------------

	*/

	

	//clock.join();
	return 0;
}

