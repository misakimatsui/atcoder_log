#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
using Graph = vector<vector<int>>;

int main() {
    int N, M; cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
    }

    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
    vector<int> cnt(N, 0);
    queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = 0;
    que.push(0); // 0 を橙色頂点にする
    cnt[0] = 0;

    // BFS
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1 && dist[nv] < dist[v]) {
                cnt[nv] += std::abs(cnt[v] - (cnt[nv] + 1)) + 1;
            }
            else {
                dist[nv] = dist[v] + 1;
                cnt[nv] = cnt[v] + 1;
                que.push(nv);
            }
        }
    }
    int ans = N;
    for (int i = 0; i < N; ++i) {
        ans += cnt[i];
    }
    std::cout << ans << std::endl;

}