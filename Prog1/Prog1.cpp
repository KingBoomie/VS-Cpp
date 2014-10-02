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

using namespace std;

void printVec(vector<int> nums){
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



vector<long> primeSundaram(long max){ // http://en.wikipedia.org/wiki/Sieve_of_Sundaram
	
	//TODO: finish this!

	vector<long> primes;
	vector<long> sieve(max);

	vector<long> toDelete(max);


	iota(sieve.begin(), sieve.end(), 1); // fill with nums from 1 to max

	bool loopBreak = 1;
	for (int j = 1;loopBreak; ++j){ // remove the unneccesary nums
		for (int i = 1;i < max/2; ++i){
			if (i + j + 2 * i * j >= sieve.size() ){
				continue;
			}
			sieve.erase(sieve.begin() + i + j + 2*i*j - 1);
		}
	}
	return sieve;
}

bool checkPrime(long long num){

	if (num == 1) return true;
	if (num == 2) return true;
	if (num % 2 == 0) return false;


	for (int i = 3; i*i <= num; i += 2){
		if (num % i == 0){
			return false;
		}
	}
	return true;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//thread clock(consoleclock);
	
	Sleep(100);

	cout << power(5, 7);
	vector<long> arvud = primeSundaram(100);
	for (auto i : arvud) cout << i << endl;
	
	/*for (auto i : arvud){
		cout << i << (checkPrime(i) ? " on algarv\n" : " ei ole algarv\n");
	}*/
	

	

	//clock.join();
	return 0;
}

