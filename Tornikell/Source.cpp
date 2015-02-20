#include <iostream>
#include <array>
#include <algorithm>
using namespace std;


array<bool, 720> calculate_offline () {
	array<bool, 720> data;
	array<int, 4> seierid = { 0, 0, 0, 0 };
	fill (data.begin (), data.end (), 0);

	bool last_loop_passed = false;
	//for 12 hours do
	for (int i = 0; i < 720;++i) {
		//		update seierid pos
		// 0 on siinpoolne tund, 1 on siinpoolne minut jne
						  seierid[0] = (seierid[0] + 1) % 60;
		if (i % 12 == 0) { seierid[1] = (seierid[1] + 1) % 60; }
		if (seierid[2] == 0) seierid[2] = 60;
		if (seierid[3] == 0) seierid[3] = 60;
						  seierid[2]--;
		if (i % 12 == 0) { seierid[3]--; }

		//		if pos equals 
		for (int o = 0; o < 4; ++o) {
			for (int oo = 0; oo < 4; ++oo) {
				if (o == oo) { continue; }
				if (seierid[o] - seierid[oo] == 0) { data[i] = true; } // they eare equal, set data to 1
				if (seierid[o] - seierid[oo] == 2) {
					if (!last_loop_passed) {
						data[i] = true;
						last_loop_passed = true; // WARNING: might not actually give the correct answer
					} else {
						last_loop_passed = false;
						cout << "set last_loop_passed to false \n";
					}
				}
			}
		}

	}
	return data;
}

void printarr (array<bool, 720> arr) {
	for (int i = 0; i < 720; ++i) {
		cout << arr[i];
		if ((i+1) % 60 == 0) {
			cout << "\n";
		}
	}
	cout << "\n";
}

int main () {
	array<bool, 720> data = calculate_offline ();
	printarr (data);
	cout << "So many thingys: " << count (data.begin (), data.end (), true);
	cin.ignore ();
	return 0;
}