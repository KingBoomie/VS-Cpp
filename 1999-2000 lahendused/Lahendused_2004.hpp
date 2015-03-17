#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

namespace y2004 {
	namespace lahendus1 {
		int current_i_base = 10;
		int current_o_base = 10;

		int lahendus1 () {
			std::ifstream input;
			std::ofstream output;

			input.open ("ekalk.sis"); 
			output.open ("ekalk.val");

			int number_of_lines;
			input >> number_of_lines;

			for (int i = 0; i < number_of_lines; ++i) {

				int curnum;
				if (current_i_base == 10) {
					
				} else {
				
				}
			}

			
			

			output.close ();
			input.close ();
			return 0;
		}
	}
}