#pragma once

#include "stdafx.h"
#include <vector>
#include <string> // to_string
#include <tuple> 
using namespace std;

class BloomFilter {

	int filterSize; //m 10
	int hashNum; // k 1
	const int elementNum; // n 20
	const double probablilityFalsePositive = 0.1;

	std::vector<bool> bitArr;

	std::vector<unsigned> hash (std::string element);

public:
	BloomFilter (const int elementNum);
	

	bool test (std::string element);
	void insert (std::string element);

	void printBitA() {
		for (auto i : bitArr) {
			cout << i << ' ';
		}
		cout << endl;
	}
};

static std::tuple<unsigned, unsigned> fnv_hash(std::string data) {

	//const unsigned offset_basis = 2166136261; // 32bit
	//const unsigned FNV_prime = 16777619; //32 bit

	const unsigned long long offset_basis = 14695981039346656037; // 64bit
	const unsigned long long FNV_prime = 1099511628211; // 64bit

	unsigned long long hash = offset_basis;

	for (auto c : data) {
		hash = (hash ^ c) * FNV_prime;
	}

	// Split the 64bit hash into to 2 32bit hashes
	return std::make_tuple((unsigned)(hash),(unsigned)(hash >> 32));
}



