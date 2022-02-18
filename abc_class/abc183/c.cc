#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<long int>>;

Graph P;
long int n, k;
long int ans = 0;
//30分

void dfs(const Graph &G, long int v, vector<bool> seen, long int sum) {
    seen[v] = true; // v を訪問済にする
    auto it = std::find(seen.begin(), seen.end(), false);
    if (it == seen.end()) {
        if (sum + P[v][0] == k) {
            ans++;
        }
    }
    if (sum < k) {
        // v から行ける各頂点 next_v について
        for (auto next_v : G[v]) { 
            if (seen[next_v]) continue; // next_v が探索済だったらスルー
            dfs(G, next_v, seen, sum + P[v][next_v]); // 再帰的に探索
        }
    }
}

int main() {
    // 頂点数と辺数
    std::cin >> n >> k;

    P.assign(n, std::vector<long int>(n, 0));
    Graph G(n);

    for (long int i = 0; i < n; ++i) {
        for (long int j = 0; j < n; ++j) {
            long int t;
            std::cin >> t;
            if (i == j) {
                continue;
            }
            P[i][j] = t;
            G[i].push_back(j);
        }
    }
    vector<bool> seen;
    seen.assign(n, false);
    dfs(G, 0, seen, 0);
    std::cout << ans << std::endl;
}