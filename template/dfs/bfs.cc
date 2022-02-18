#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
using Graph = vector<vector<int>>;

//最短経路の長さと個数

int main() {
    int N, M; cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
    vector<int> cnt(N);
    queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = 0;
    que.push(0); // 0 を橙色頂点にする
    cnt[0] = 1;

    // BFS
    int ans = 0;
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) {
                if (dist[nv] + 1 == dist[v]) {
                    cnt[v] += cnt[nv];
                    cnt[v] %= static_cast<int>(std::pow(10, 9) + 7);
                }
            }
            else {
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }

    std::cout << cnt[N-1] << std::endl;
}