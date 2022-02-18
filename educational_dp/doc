#include <iostream>
#include <vector>

static int path_map[100001][100001];

int solve(std::vector<int>& dp, int i, int length) {

	int ans = 0;
	for (int y = 1; y <= length; ++y) {
		if (i != y && 0 != path_map[y][i]) {
			if (-1 == dp[y]) { 
				ans = std::max(ans, 1 + solve(dp, y, length));
			}
			else {
				ans = std::max(ans, 1 + dp[y]);
			}
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		std::cin >> y >> x;
		++path_map[y][x];
	}

	std::vector<int> dp(n+1, -1);

	for (int i = 1; i <= n; ++i) {
		dp[i] = solve(dp, i, n);
	}

	int max = 0;
	for (auto x : dp) {
		max = std::max(max, x);
	}
	std::cout << max << std::endl;
}
