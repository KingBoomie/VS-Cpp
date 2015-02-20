#include <fstream>
#include <vector>
using namespace std;

namespace y2008{
	namespace lahendus2 {

		int lahendus2(){
			ifstream input;
			input.open("jada.sis");

			ofstream output;
			output.open("jada.val");
			//output << max << " " << min;

			output.close();
			input.close();
			return 0;
		}
	}
}