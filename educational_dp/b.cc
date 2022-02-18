#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <array>
#include <map>
#include <climits>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, k;
	std::cin >> n >> k;
	std::vector<int> p;
	std::vector<int> dp(n, INT_MAX);
	for (int i = 0; i < n; ++i) {
		int num;
		std::cin >> num;
		p.push_back(num);
	}
	dp[0]  = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= std::min(i, k); ++j) {
			dp[i] = std::min(dp[i], std::abs(p[i - j] - p[i]) + dp[i - j]);
		}
	}
	std::cout << dp[n - 1] << std::endl;
}



