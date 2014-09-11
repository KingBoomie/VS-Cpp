#include "stdafx.h"
#include "functions.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums = getRand(5, 4, 10, 1);

	for (auto i : nums){
		cout << i << " ";
	}
	return 0;
}

