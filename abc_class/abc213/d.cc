#include <iostream>
#include <vector>
#include <set>

using namespace std;
using Graph = vector<set<int>>;

int tmp = -1;
// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー

        if (tmp != v) {
            std::cout << v + 1<< std::endl;
        }
        tmp = v;


        dfs(G, next_v); // 再帰的に探索
    }
    if (tmp != v) {
        std::cout << v + 1<< std::endl;
    }
    tmp = v;
}

int main() {
    // 頂点数と辺数
    int N, M;
     cin >> N;
     M = N - 1;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].insert(b);
        G[b].insert(a);
    }

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0);
}