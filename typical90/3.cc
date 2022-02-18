#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;


int max_len = 0;
int max_point = 0;
// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v, int len) {
    seen[v] = true; // v を訪問済にする
    if (max_len <= len) {
        max_len = len;
        max_point = v;
    }

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, len+1); // 再帰的に探索
    }
}

int main() {
    int N;
    cin >> N;

    Graph G(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0, 0);
    max_len = 0;
    seen.assign(N, false); 
    dfs(G, max_point, 0);
    std::cout << max_len + 1 << std::endl;
}