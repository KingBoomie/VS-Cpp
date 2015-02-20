#pragma once
// Uses input from cin instead of files
// Made by Kristjan Laht 6.02.2015

#include <fstream>
#include <vector>

namespace y2000{
	namespace lahendus1 {

		struct each_unique{
			int first_instance_location;
			int last_instance_location;
			int smallest_delta;
			int number;
		};

		int lahendus1(){
			std::ifstream input;
			input.open("jada.sis");

			int number_of_nums;
			input >> number_of_nums;

			std::vector<each_unique> uniques;

			for (int i = 0; i < number_of_nums; ++i){
				int cur_num;
				input >> cur_num;

				bool found = false;

				for (auto &num_in_vec : uniques){
					if (num_in_vec.number == cur_num){
						found = true;

						if (num_in_vec.smallest_delta < i - num_in_vec.last_instance_location){
							num_in_vec.smallest_delta = i - num_in_vec.last_instance_location;
						}
						num_in_vec.last_instance_location = i;
						break;
					}
				}

				if (!found){ // Initialize and add a new unique number to the vector
					each_unique newer;
					newer.number = cur_num;
					newer.smallest_delta = -1;
					newer.first_instance_location = i;
					newer.last_instance_location = i;
					uniques.push_back(newer);
				}
			}

			unsigned max = 0, min = -1; // min has a quick and lazy hack to make it a close value to MAX_INT
			for (auto numb : uniques){
				if (numb.last_instance_location - numb.first_instance_location > max) {
					max = numb.last_instance_location - numb.first_instance_location;
				}
				if (numb.smallest_delta < min){
					min = numb.smallest_delta;
				}
			}

			std::ofstream output;
			output.open("jada.val");
			output << max << " " << min;

			output.close();
			input.close();
			return 0;
		}
	}
}



