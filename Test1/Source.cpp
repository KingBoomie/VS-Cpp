
int fib (int num) {
	int a = 0;
	int b = 1;
	int c;
	for (int i = 0; i < num; ++i) {
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

int main() {
	volatile int a = fib (5);

	return 0;
}

