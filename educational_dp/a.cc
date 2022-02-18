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

	int n;
	std::cin >> n;

	std::vector<int> p;
	std::vector<int> dp;

	for (int i = 0; i < n; ++i) {
		int num;
		std::cin >> num;
		p.push_back(num);
		dp.push_back(0);
	}
	dp[0] = 0;
	dp[1] = std::abs(p[1] - p[0]);

	for (int i = 2; i < n; ++i) {
		dp[i] = std::min(std::abs(p[i - 1] - p[i]) + dp[i - 1],  std::abs(p[i - 2] - p[i]) + dp[i - 2]);
	}
	std::cout << dp[n - 1] << std::endl;

}


