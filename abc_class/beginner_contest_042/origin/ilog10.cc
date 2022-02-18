#include<iostream>

int ilog10(unsigned x) {
	int i;
	static unsigned table[11] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 0xFFFFFFFF};
	for (i = -1; ; ++i) {
		if (x <= table[i+1]) {
			return i;
		}
	}
}

int main(void) {
	int x;
	std::cin >> x;
	std::cout << ilog10(x) << std::endl;
}
