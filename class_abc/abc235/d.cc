#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
using Graph =  map<int, vector<int>>;
map<int, bool> seen;
int AA;
int answer = INT_MAX; 

int digsum(int n) {
    int res = 0;
    while(n > 0) {
        res++;
        n /= 10;
    }
    return res;
}

bool judgea(int val, int a) {
    if (val % a == 0) {
        return true;
    }
    return false;
}

bool judgeb(int val) {
    if (1 < digsum(val)) {
        return true;
    }
    return false;
}

void add(Graph &G, int nn) {
    if (nn == 58) {
        int nnnnnnnnnnnn = 0;

    }
    if (judgea(nn, AA)) {
        G[nn].push_back(nn/AA);
    }
    if (judgeb(nn)) {
       int tmp = std::pow(10, digsum(nn) - 1);
       int tmp2 = std::pow(10, digsum(nn) - 1 - 1);
       int val = nn % tmp * 10 + nn / tmp;
         G[nn].push_back(val);
    }
}



void dfs(Graph &G, int v, int ans) {
    seen[v] = true; // v を訪問済にする
    if (v == 1) {
        answer = std::min(ans, answer);
    }
    add(G, v);
    ++ans;
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, ans); // 再帰的に探索
    }
}
int main() {
    int n;
    cin >> AA >> n;
    Graph G;
    int ans = 0;
    dfs(G, n, ans);
    if (answer == INT_MAX) {
    std::cout << -1 << std::endl;

    }
    else {
        std::cout << answer << std::endl;

    }
}