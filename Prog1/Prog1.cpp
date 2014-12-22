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
#include <numeric>
*/

#include "functions.h"
#include "euler.h"
#include "BloomFilter.h"

using namespace std;

template <typename T>
void print(T nums){
	for (auto i : nums){
		cout << i << " ";
	}
	cout << endl;
}

vector<int> naiveDivisors(int num){
	vector<int> divs;
	for (int i = 1; i <= num; ++i){
		if (num % i == 0){
			divs.push_back(i);
		}
	}
	return divs;
}

void printTime(float time){
		cout << "Function running time: " << time << "\n";
}


vector<int> combinations(int num){
	string str = to_string(num);
	vector<int> combinations;
	for (int i = 0; i < power(2, str.size());++i){
		for (int j = 0; j < str.size(); ++j){
			if (i & (j << 1));
			combinations.push_back(j);
		}
	}
	return combinations;
}




int _tmain(int argc, _TCHAR* argv[])
{
	thread consoleTime(consoleclock);
	Sleep(10);

	//print (divisiors (100));
	string str = "Tere";

	BloomFilter filter (20);

	filter.insert (str);

	cout << filter.test ("Teree") << endl;
	cout << filter.test (str) << endl;
	filter.printBitA();

	consoleTime.join();
	return 0;
}

