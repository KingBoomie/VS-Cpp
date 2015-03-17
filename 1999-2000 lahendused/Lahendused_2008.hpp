#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

namespace y2008{
	namespace lahendus2 {

		template<typename T>
		std::vector<T> &split_into_T(const std::string &s, char delim, std::vector<T> &elems) {
			std::stringstream ss(s);
			std::string item;
			while (std::getline(ss, item, delim)) {
				elems.push_back(T(item));
			}
			return elems;
		}

		int stoi(const char ch){
			return ch - '0';
		}


		struct Element {
			char name;
			int atom_num;

			Element(){
				name;
				atom_num;
			}
			Element(char name_){
				name = name_;
				atom_num = 1;
			}
			Element(char name_, int atom_num_){
				name = name_;
				atom_num = atom_num_;
			}
			Element(std::string str){
				if (str.size() == 3){
					name = str[1];
					atom_num = stoi(str[0]) * stoi(str[2]);
				}
				else if (str.size() == 2){
					name = str[0];
					atom_num = stoi(str[1]);
				}
				else{
					name = str[0];
					atom_num = 1;
				}
			}
			Element operator*(const int& other){
				return Element(name, atom_num * other);
			}
			Element operator==(const Element& other){
				return name == other.name && atom_num == other.atom_num; 
			}
		};

		struct Equation {
			std::vector<Element> right_elements; // TODO: change from vectors to something sorted
			std::vector<Element> left_elements; // TODO: change from vectors to something sorted

			Equation(){
				right_elements;
				left_elements;
			}

			Equation(std::string &str){
				std::stringstream ss(str);
				std::string element_string;

				std::getline(ss, element_string, '=');
				split_into_T<Element>(element_string, '+', right_elements);

				std::getline(ss, element_string);
				split_into_T<Element>(element_string, '+', left_elements);
			}
			bool balanced(Equation eq){
				return false;

				// TODO: this has a problem when comparing stuff with different names
				// to counter, make sure the names are in order before comparing 
			}
		};
		
		int lahendus2(){
			std::ifstream input;
			input.open("rv.sis");

			int N;
			input >> N;
			
			// INPUT
			std::vector<Equation> equations(N);
			std::string item;
			for (auto &equation : equations){
				std::getline(input, item);
				equation = Equation(item); 
			}

			std::ofstream output;
			output.open("rv.val");

			output.close();
			input.close();
			return 0;
		}
	}
}