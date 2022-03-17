#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
using Graph =  vector<vector<int>>;
std::array<int, 11> seen;

int ans = 0;
void dfs(Graph &G, int v, int depth, int node) {
    seen[v] = depth;
    if (v == node) {
        ++ans;
    }
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v] != -1 && seen[next_v] <= depth) {
            continue; // next_v が探索済だったらスルー
        }
        dfs(G, next_v, 1+depth, node); // 再帰的に探索
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    Graph G(n);
    seen.fill(-1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(G, 0, 0, n - 1);
    std::cout << ans << std::endl;
}