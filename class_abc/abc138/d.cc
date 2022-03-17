#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
vector<int> table;
vector<int> ans;
void dfs(const Graph &G, int v, int sum) {
    seen[v] = true;
    ans[v] = table[v] + sum;
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; 
        dfs(G, next_v, table[v] + sum); 
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    Graph G(N);
    for (int i = 1; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    table.assign(N, 0);
    ans.assign(N, 0);
    for (int i = 0; i < Q; ++i) {
        int p, x;
        cin >> p >> x;
        --p;
        table[p] += x;
    }
    seen.assign(N, false);
    dfs(G, 0, 0);
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << endl;
    }
}