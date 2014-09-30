#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>

///<summary>
///Return: vector of ints
///<para>Usage: getRand (number of ints, minimum value, maximum value,</para>
///0/1/2 = random sequence/sorted_asc/sorted_desc)
///</summary>
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


///<summary>
///Return: float seconds of running time
///<para>gets function pointer and arguments as an intializer list</para>
///</summary>
float timer(void(*f)(std::initializer_list<int>), std::initializer_list<int> args){
	clock_t time = clock(); //get initial value of time

	(*f)(args); //execute function

	time = clock() - time;
	return (float)time / CLOCKS_PER_SEC;
}