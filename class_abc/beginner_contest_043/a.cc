#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <array>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::vector<std::string> arr;

	for (int i = 0; i < 10; ++i) {
		std::string  c;
		std::cin >> c; 
		if (c == "B" && arr.size() != 0) {
			arr.pop_back();
		}
		else if (c =="1" || c =="2") {
			arr.push_back(c);
		}
		for (auto x : arr) {
			std::cout << x;
		}
		std::cout << std::endl;;
	}
}


