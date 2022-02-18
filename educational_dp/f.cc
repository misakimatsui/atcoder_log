#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <array>
#include <map>

int dp[3100][3100] = {0};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string  s_str, t_str;
	std::cin >> s_str >> t_str;

	int max_size = 0;
	for (int i = 1; i <= t_str.size(); ++i) {
		for (int j = 1; j <= s_str.size(); ++j) {
			if (t_str[i-1] == s_str[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = std::max(dp[i][j-1],  dp[i-1][j]);
			}
			max_size = std::max(max_size, dp[i][j]);
		}
	}
	int count = 0;
	int x  = s_str.size();
	int y  = t_str.size();
	std::string ans = "";
	while (x > 0 && y > 0) {

		if (dp[y][x - 1] == dp[y][x]) {
			--x;
		}
		else if (dp[y - 1][x] == dp[y][x]) {
			--y;
		}

		else {
			ans = s_str[x-1] + ans;
			--x;
			--y;
		}
	}
	std::cout << ans << std::endl;
}
