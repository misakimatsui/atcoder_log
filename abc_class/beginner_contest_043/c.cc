#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <array>
#include <climits>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::vector<int> vec, unique;
	std::cin >> n;


	float sum = 0;
	for (int i = 0; i < n; ++i) {
		int  c;
		std::cin >> c; 
		vec.push_back(c);
		unique.push_back(c);
		sum += c;
	}
	sum /= n;
	int ave = static_cast<int>(sum);
	if (0 != (sum - ave)) {
	}
	int min = INT_MAX;
	for (int i = ave - 1; i <= ave + 1; ++i) {
		float ans = 0;
		for (auto x : vec) {
			ans += ((x - i) * (x - i));
		}
		if (ans < min) {
			min = ans;
		}
	}
	std::cout << min << std::endl;

}


