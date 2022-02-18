#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


vector<int> topo_sort(const std::vector<std::vector<int>> &G) {  // bfs
    vector<int> ans;
    int n = (int)G.size();
    vector<int> ind(n);            // ind[i]: 頂点iに入る辺の数(次数)
    for (int i = 0; i < n; i++) {  // 次数を数えておく
        for (auto e : G[i]) {
            ind[e]++;
        }
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> que;
    for (int i = 0; i < n; i++) {  // 次数が0の点をキューに入れる
         if (ind[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {  // 幅優先探索

        int now = que.top();
        ans.push_back(now);
        que.pop();
        for (auto e : G[now]) {
            ind[e]--;
            if (ind[e] == 0) {
                que.push(e);
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

	std::vector<std::vector<int>> g(n+1);

	for (int i = 0; i < m; ++i) {
		int x, y;
		std::cin >> x >> y;
		g[x].push_back(y);
	}
	auto result = topo_sort(g);
    if (result.size() -  1 == n) {
        for (int i = 1; i < result.size(); ++i) {
            std::cout << result[i] << " ";
        }
	    std::cout << std::endl;
    }
    else {
        std::cout << "-1" << std::endl;
    }

}
