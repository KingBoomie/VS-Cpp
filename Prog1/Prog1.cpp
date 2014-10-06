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


template<typename T>
void removeDupAndSort(&vector<T> vec, bool sortWay = 1){
	if (sortWay) {
		sort(vec.begin(), vec.end()); 

	}else{
		sort(vec.begin(), vec.end(), [](int a, int b) { return b < a; });
	
	}
	auto end_unique = unique(vec.begin(), vec.end()); // where the uniques end and duplicates start
	vec.erase(end_unique, vec.end());
}

vector<long> primeSundaram(long max){ // http://en.wikipedia.org/wiki/Sieve_of_Sundaram
	
	//TODO: make it compile

	vector<long> primes;


	//auto comp = [](long &a, long &b) -> {return a < b; };
	vector<long> toDelete;

	bool loopBreak = 1;
	for (int j = 1; j*2 < max; ++j){ 
		for (int i = 1; i*2 < max; ++i){
			if (i + j + 2 * i * j >= max ){
				break;

			}

			toDelete.push_back(i + j + 2*i*j);
			//cout << i + j + 2 * i*j << endl;
		}
	}

	//remove duplicates
	removeDupAndSort(toDelete*, false);

	// i + j + ji2
	for (int i = 3; i < max; ++i){
		if (i == toDelete.top()){
			toDelete.();
			//TODO fix this, now that i'm using vecotrs
		}else{
			primes.push_back(i * 2 + 1);
		}
	}


	return primes;
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
	//thread consoleTime(consoleclock);
	
	Sleep(100);

	vector<long> arvud = primeSundaram(50);
	cout << endl << endl;
	for (auto i : arvud) cout << i << endl;
	

	/*for (auto i : arvud){
		cout << i << (checkPrime(i) ? " on algarv\n" : " ei ole algarv\n");
	}*/
	

	

	//consoleTime.join();
	return 0;
}

