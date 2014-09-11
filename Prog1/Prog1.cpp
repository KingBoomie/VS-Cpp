#include "stdafx.h"
#include "functions.h"

using namespace std;
//
float time(void(*f)(int)){
	clock_t time = clock(); //get initial value of time
	
	(*f)(10000); //execute function in arg[0] with argument of it's own: 10000

	time = clock() - time;
	return (float)time / CLOCKS_PER_SEC;
}

void printNums(int count) {
	vector<int> nums = getRand(count, 1, 1000);

	for (auto i : nums){
		cout << i << "\n";
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Time: " << time(printNums) << " seconds.\n";
	
	return 0;
}

