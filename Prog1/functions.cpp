#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>

///<summary>
///Return: vector of ints
///<para>Usage: getRand (number of ints, minimum value, maximum value,</para>
///0/1/2 = random sequence/sorted_asc/sorted_desc)
///</summary>
std::vector<int> getRand(int count, int min, int max, int type = 0){
	//TODO: use templates
	std::vector<int> data(count);

	srand(time(NULL)); //set seed as current time

	int span = max - min;

	for (int i = 0; i < count; ++i){
		data[i] = rand() % span + min;
	}
	if (type == 0){
		std::cout << "Random numbers returned" << std::endl;

	}
	else if (type == 1){
		sort(data.begin(), data.end());
		std::cout << "Random sorted ascending numbers returned" << std::endl;

	}
	else if (type == 2){
		sort(data.begin(), data.end(), [](int a, int b) { return b < a; });
		std::cout << "Random sorted descending numbers returned" << std::endl;
	}
	return data;
}

