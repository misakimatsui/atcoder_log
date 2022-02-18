#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <array>
#include <map>


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::string str;
	std::map<int, int> vec;

	std::cin >> str;

	for (int i = 0; i < str.size(); ++i) {
		char n = (str[i]);
		vec[n]++;

	}
	for (auto [_, x] : vec) {
		if (0 != (x % 2)) {
			std::cout << "No" << std::endl;
			return 0;
		}
	}
	std::cout << "Yes" << std::endl;

}


