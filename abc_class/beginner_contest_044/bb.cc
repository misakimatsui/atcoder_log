#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <array>


int to_int(const char c){
	if('a' <= c && c <= 'z') return (c-'a'+1);
	return -1;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::string str;
	std::vector<int> vec(25, 0);

	std::cin >> str;

	for (int i = 0; i < str.size(); ++i) {
		int n = to_int(str[i]);
		vec[n]++;

	}
	for (auto x : vec) {
		if (0 != (x % 2)) {
			std::cout << "No" << std::endl;
			return 0;
		}
	}
	std::cout << "Yes" << std::endl;

}


