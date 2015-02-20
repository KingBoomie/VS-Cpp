#include "BloomFilter.h"


BloomFilter::BloomFilter (const int elementNum) : elementNum (elementNum){

	double tempSize = -1.0 * (double)elementNum * log (probablilityFalsePositive) / log (2) / log (2);
	filterSize = tempSize;
	hashNum = (tempSize / (double)elementNum * log (2) + 0.5);
	bitArr.resize (elementNum);
}
//
//filterSize ((const int)(double)elementNum * log (probablilityFalsePositive) / log (2) / log (2)),
//hashNum (filterSize / elementNum * log (2)) {
//
std::vector<unsigned> BloomFilter::hash (std::string element) {

http://willwhim.wpengine.com/2011/09/03/producing-n-hash-functions-by-hashing-only-once/

	std::vector<unsigned> returnVal (hashNum);

	unsigned hash1, hash2;
	std::tie (hash1, hash2) = fnv_hash (element);

	unsigned count = 0;
	for (auto &hash : returnVal) { // give each element in vector a hash value
		hash = (hash1 + hash2 * count) % filterSize;
		count++;
	}

	return returnVal;
}

void BloomFilter::insert (std::string element) {
	std::vector<unsigned> hashes (hash (element));

	for (auto hash : hashes) {
		bitArr[hash] = true;
	}
}

bool BloomFilter::test (std::string element) {
	std::vector<unsigned> hashes (hash (element));

	for (auto hash : hashes) {
		if (!bitArr[hash]) return false;
	}
	return true;
}
