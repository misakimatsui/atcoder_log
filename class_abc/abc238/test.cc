#include <bits/stdc++.h>
#include <cmath>
#include <climits>

int main(void) {
	std::cout << INT_MAX <<  std::endl;
	std::cout << LONG_MAX <<  std::endl;
	std::cout << DBL_MAX <<  std::endl;
	std::cout << LONG_LONG_MAX <<  std::endl;
	long int val = 9;
	long int pow10 = 1;

	for (long int i = 1; i <= 18; ++i) {
		pow10 *= 10;
		val = pow10 * 9 + val;
		std::cout << val << std::endl;
	}
}
