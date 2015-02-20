#include <map>
#include <vector>


void findRoute (int N, int a, int b);
int ping (int i, int j);
void travelTo (int k);

void findRoute (int N, int a, int b) {


	// shortest route:
	/*
		find dist to compare to
		start from a, find computers that have 0 as their dist. 
		for each shortest/0
			ping(shortest, end), find smallest(might be several)
			branch 

	  */

	int dist = ping (a, b);




}

inline bool checkVisited (int num, std::vector<int> visited) {
	for (auto i : visited) {
		if (num == i) {
			return true;
		}
	}
	return false;
}

std::map<int, std::pair<int, int> > pings;
void findRouteback (int N, int a, int b, std::vector<int> visited = {}) {

	for (int i = 0; i < N; ++i) {
		if (!checkVisited (i, visited)) {
			
			ping (a, i);
			
		}
	}
}