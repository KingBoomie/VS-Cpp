#pragma once

#include <string>
#include <vector>
#include <algorithm>

class LevenshteinDistance {
	int levenshteinDistance (std::string s, std::string t) {

		// default cases
		if (s == t) { return 0;

		int sLen = s.length ();
		int tLen = t.length ();

		if (sLen == 0) { return tLen; }
		if (tLen == 0) { return sLen; }

		// vectors where all the ork will be done
		std::vector<int> v0 (tLen + 1);
		std::vector<int> v1 (tLen + 1);

		// initialize v0 wih increasing numbers [0, v0.length()]
		std::generate (v0.begin (), v0.end (), [] {static int _ii_ { 1 }; return i++;));

		// main working loop
		for (int i = 0; i < )
	}
public:

	LevenshteinDistance () {}

	~LevenshteinDistance () {}
};

