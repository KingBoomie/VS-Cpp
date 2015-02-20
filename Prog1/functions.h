#pragma once

/////////////////////////////////////
//			Algorithms
/////////////////////////////////////

/** Returns long long number that was put to a power
* Using exponation by squaring algorithm
*/
template <typename T>
T power (int num, unsigned int power);

/*
	Checks for prime by trying out every number
*/
template <typename T>
bool checkPrime(T num);

/*
	Generates a vector of prime numbers, using Sundaram's alogorithm
*/
//template <typename T, typename A>
//std::vector<T, A> primeSundaram(T max);
std::vector<int> primeSundaram (int max);

//long long fibonacci (int i);

//////////////////////////////////////
//			Misc functions
//////////////////////////////////////


///<summary>
///Return: vector of ints
///<para>Usage: getRand (number of ints, minimum value, maximum value,</para>
///0/1/2/3/4/5 = random sequence/sorted_asc/sorted_desc/w.o duplicates_asc/w.o duplicates_desc/const)
///</summary>
std::vector<int> getRand(const int count, const int min, const int max, const int type = 0);

///<summary>
///Return: float seconds
///<para>Usage: timer (std::bind( &function, arguments) )</para>
///</summary>
float timer(std::function<void()> f);

// Updates time in console window
void consoleclock();