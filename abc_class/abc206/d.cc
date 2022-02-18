#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;
using ll = long int;


class UnionFind {
public:
    // 最初は全てが根であるとして初期化
    UnionFind(int N) : par_(N) { for (int i = 0; i < N; ++i) par_[i] = -1; }
    UnionFind(const UnionFind&) = delete;
    UnionFind& operator=(const UnionFind&) = delete;

    void unite(int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v)
            return;
        par_[u] = v;
    }

    bool same(int u, int v) {
        if (root(u) == root(v))
            return true;
        return false;
    }

    // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    int root(int pos) {
        if (par_[pos] == -1) {
            return pos; 
        }
        return par_[pos] = root(par_[pos]);
    }
    // par_[i]:iの親の番号　(例) par_[3] = 2 : 3の親が2
    std::vector<int> par_;
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    std::cin >> n;
    std::vector<ll> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }
    int max = *max_element(vec.begin(), vec.end());
    UnionFind uf(max+1);
    int ans = 0;
    for (int l = 0, r = vec.size()-1; l < r; ++l, --r) {
        if (!uf.same(vec[l], vec[r])) {
            uf.unite(vec[l], vec[r]);
            ans++;
        }
    }
    std::cout << ans << std::endl;
}