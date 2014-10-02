#ifndef FUNCTIONS_H 
#define FUNCTIONS_H

///<summary>
///Return: vector of ints
///<para>Usage: getRand (number of ints, minimum value, maximum value,</para>
///0/1/2/3/4/5 = random sequence/sorted_asc/sorted_desc/w.o duplicates_asc/w.o duplicates_desc/const)
///</summary>
std::vector<int> getRand(const int count, const int min, const int max,const int type = 0);



///<summary>
///Return: float seconds
///<para>gets function pointer and arguments as an intializer list</para>
///</summary>
float timer(void(*f)(std::initializer_list<int>), std::initializer_list<int> args);

///<summary>
///Return: float seconds
///<para>gets function pointer and a vector of ints of arguments</para>
///</summary>
float timer(void(*f)(std::vector<int>), std::vector<int> args);

///<summary>Updates time in console window</summary>
void consoleclock();


#endif
