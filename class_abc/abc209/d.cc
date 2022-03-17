#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
using Graph = vector<vector<int>>;

//最短経路の長さと個数

int main() {
    int n, q;
     cin >> n >> q;

    Graph G(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist(n, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = 0;
    que.push(0); // 0 を橙色頂点にする

    // BFS
    int ans = 0;
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) {
            }
            else {
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int c, d;
        std::cin >> c >> d;
        --c;
        --d;
        if (std::abs(dist[c] - dist[d]) % 2 == 1) {
            std::cout << "Road" << std::endl;
        }
        else {
            std::cout << "Town" << std::endl;
        }
    }
}