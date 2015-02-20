// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int fib (int num) {
	int a = 0;
	int b = 1;
	int c;
	for (int i = 0; i < num; ++i) {
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

int _tmain(int argc, _TCHAR* argv[])
{
	fib (5);
	
	return 0;
}

