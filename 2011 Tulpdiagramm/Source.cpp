//#include <fstream>
//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <sstream>
//#include <string>
//#include <array>
//
//
//using namespace std;
//enum out {screen, file};
//
//void output (unsigned output, string str) {
//	if (output == screen) { cout << str; }
//	if (output == file) {
//		ofstream out("tulp.val");
//		out << str;
//	}
//	return;
//}
//
//int main () {
//	ifstream input;
//	input.open ("tulp.sis");
//
//	unsigned N, minimum = -1 , maximum = 0;
//	input >> N;
//	
//	for (int i = 0; i < N; ++i) {
//		unsigned current;
//		input >> current;
//		if (current < minimum) { minimum = current; }
//		if (current > maximum) { maximum = current; }
//	}
//	input.close ();
//
//	array<int, 19> arvud = { 1, 10, 100, 1000, 10000, 100000, 2, 20, 200, 2000, 20000, 200000, 5, 50, 500, 5000, 50000, 500000, 1000000 };
//
//	unsigned samm;
//	for (int i = 0; samm <= 10 && i < 19; ++i) {
//		samm = ceil (float (maximum - minimum + 2) / float (arvud[i]));
//	}
//
//
//
//
//}
