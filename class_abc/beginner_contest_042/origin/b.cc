#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, l;
	std::cin >> n >> l; 

	std::vector<std::string> vec(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[i];
	}
	std::sort(vec.begin(), vec.end());

	for (auto X : vec) {
		std::cout << X;
	}
	std::cout << std::endl;
}


