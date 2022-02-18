#include <iostream>
#include <vector>

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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int H, W, Q;
    std::cin >> H >> W;
    std::cin >> Q;
    UnionFind uf(H * W);
    int pre = -1;

    for (int i = 0; i < Q; ++i) {
        int q;
        std::cin >> q;
        if (q == 1) {
            int r, c;
            std::cin >> r >> c;
            --r; --c;
            int point = r * W + c;
            if (pre != -1) {
                uf.unite(pre, point);
            }
            pre = point;
        }
        else if (q == 2) {
            int ra, ca, rb, cb;
            std::cin >> ra >> ca >> rb >> cb;
            --ra; --ca; --rb; --cb;
            if (uf.same(ra * W + ca, rb * W + cb)) {
                std::cout << "Yes" << std::endl;
            }
            else {
                std::cout << "No" << std::endl;
            }
        }
    }
}
