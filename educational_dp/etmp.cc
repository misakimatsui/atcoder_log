#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <array>
#include <map>

template <int X, int N>
struct pow {
	static const int value = X * pow<X, N - 1>::value;
};
template <int X>
struct pow<X, 0> {
	static const int value = 1;
};


long int weights[110];
long int values[110];
long int dp[110][100100];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, w;
	std::cin >> n >> w;

	for (int i = 0; i < 110; ++i) {
		for (int j = 0; j < 100100; ++j) {
			dp[i][j] = INT_MAX;
		}
	}

	long int max_value = 0;

	for (int i = 1; i < n + 1; ++i) {
		long int weight, val;
		std::cin >> weight >> val;
		max_value = std::max(max_value, val);
		weights[i] = weight;
		values[i] = val;
	}

	for (int i = 1; i < n+1; ++i) {
		for (int j = 0; j < max_value+1; ++j) {
			if (0 <= j - values[i] ) {
				dp[i][j] = std::min(dp[i][j - values[i]] + weights[i], dp[i - 1][j]);
			}
			else {
				dp[i][j] =  dp[i-1][j];
			}
		}
	}
	//std::cout << dp[n][w] << std::endl;

}



