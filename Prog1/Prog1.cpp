#include "stdafx.h"
#include "functions.h"

using namespace std;

void printNums(initializer_list<int> args) {
	
	vector<int> nums = getRand(args.begin()[0], args.begin()[1], args.begin()[2], args.begin()[3]);

	for (auto i : nums){
		cout << i << "\n";
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Time: " << timer(printNums, { 100000, 1, 100000, 1}) << " seconds.\n";
	
	return 0;
}

