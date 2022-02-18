#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <array>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int  n, k;
	std::cin >> n >> k; 
	std::array<bool, 10> table = {false, false, false, false, false, false, false, false, false, false};
	std::vector<int> vec(k);
	for (int i = 0; i < k; ++i) {
		int digit;
	       	std::cin >> digit;
		table[digit] = true;
		vec[i] = digit;
	}

	std::string str = "     ";
	int rank = 1;
	while (n != 0) {
		int tmp = n % 10;
		for (int i = 0; i < 10; ++i) {
			if (table[tmp]) {
				tmp = (tmp+1) % 10;
			}
			else {
				std::cout << tmp << std::endl;
				str[str.size() - rank] = '0' + tmp;
				std::cout << str << std::endl;
				++rank;
				break;
			}
		}
		n /= 10;
	}
	std::cout << std::ios::skipws << str << std::endl;
}


