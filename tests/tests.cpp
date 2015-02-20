// atomic::operator=/operator T example:
#include <iostream>       // std::cout
#include <atomic>         // std::atomic
#include <thread>         // std::thread, std::this_thread::yield
#include <vector>



class Bar {
	struct{
		std::atomic<int> foo = 0;
	}tere;

	std::vector<atomwrapper<int> >vec;

public:
	Bar(int _foo) {
		tere.foo = _foo;
	}
	void set_foo(int x) {
		tere.foo = x;
	}
	void print_foo() {
		std::cout << "foo: " << tere.foo << std::endl;
	}
};

int main()
{
	Bar bar(1);
	bar.print_foo();
	bar.set_foo(2);
	bar.print_foo();
	return 0;
}