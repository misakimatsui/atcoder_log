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


	int n, w;
	std::cin >> n >> w;
	std::vector<std::vector<long int>> dp;
	std::vector<long int> weights;
	std::vector<long int> values;

	weights.assign(n+1, 0);
	values.assign(n+1, 0);
	{
		std::vector<long int> tmp(w+1, 0);
		dp.push_back(tmp);
	}
	for (int i = 1; i < n+1; ++i) {
		long int weight, val;
		std::cin >> weight >> val;
		weights[i] = weight;
		values[i] = val;
		std::vector<long int> tmp(w+1, 0);
		dp.push_back(tmp);

	}

	for (int i = 1; i < n+1; ++i) {
		for (int j = 0; j < w+1; ++j) {
			if (0 <= j - weights[i] ) {
				dp[i][j] = std::max(dp[i - 1][j - weights[i]] + values[i], dp[i - 1][j]);
			}
			else {
				dp[i][j] =  dp[i-1][j];
			}
		}
	}
	std::cout << dp[n][w] << std::endl;

}
