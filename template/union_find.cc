#include <vector>

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