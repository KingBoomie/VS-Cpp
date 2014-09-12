#ifndef FUNCTIONS_H 
#define FUNCTIONS_H

std::vector<int> getRand(int count, const int min, const int max, int type = 0);
float timer(void(*f)(std::initializer_list<int>), std::initializer_list<int> args);

#endif
