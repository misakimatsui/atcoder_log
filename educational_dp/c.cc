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
	std::vector<std::vector<int>> dp;
	int ans;
	for (int i = 0; i < n; ++i) {
		int min = 0;
		std::vector<int> tmp(3,0);
		for (int j = 0; j < 3; ++j) {
			int num;
			std::cin >> num;
			tmp[j] = num;
		}
		dp.push_back(tmp);
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			int max = 0;
			for (int k = 0; k < 3; ++k) {
				if (j == k) continue;
				max = std::max(max, dp[i-1][k] + dp[i][j]);
			}
			dp[i][j] = max;
		}
	}
	std::cout << std::max(std::max(dp[n-1][0], dp[n-1][1]), std::max(dp[n-1][1], dp[n-1][2])) << std::endl;

}



