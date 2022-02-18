#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> g(n+1);
	std::vector<int> indigree(n+1, 0);

	for (int i = 0; i < m; ++i) {
		int x, y;
		std::cin >> x >> y;
		g[x].push_back(y);
		indigree[y]++;
	}

	// topological sort
	std::vector<std::vector<int>> sort_g;
	std::vector<int> p;
	{
		int cnt = n;
		while (0 < cnt) {
			if (0 == indigree[cnt]) {
				indigree[cnt] = -1;
				sort_g.push_back(g[cnt]);
				p.push_back(cnt);
				for (auto X : g[cnt]) {
					--indigree[X];
				}
				cnt = n;
			}
			else {
				--cnt;
			}
		}

	}

	// dp
	std::vector<int> dp(n+1, 0);
	for (int y = 0; y < sort_g.size(); ++y) {
		for (int x = 0; x < sort_g[y].size(); ++x) {
			dp[sort_g[y][x]] =  std::max(dp[sort_g[y][x]], dp[p[y]] + 1);
		}
	}

	// answer
	int ans = 0;
	for (auto x : dp) {
		ans = std::max(ans, x);
	}
	std::cout << ans << std::endl;
}
