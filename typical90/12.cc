#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

class UnionFind {
public:
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

    int root(int pos) {
        if (par_[pos] == -1) {
            return pos; 
        }
        return par_[pos] = root(par_[pos]);
    }
    std::vector<int> par_;
};

void unite(UnionFind& uf, const std::vector<std::vector<int>>& vec, int x, int y) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int w = vec[0].size();
    int h = vec.size();
    for (int i = 0; i < 4; ++i) {
        int sx = x + dx[i], sy = y + dy[i];
        if (0 <= sx && sx < w && 0 <= sy && sy < h) {
            if (vec[sy][sx]) {
                uf.unite(sy * w + sx, y * w + x);
            }
        }
    }
}

bool check(UnionFind& uf, const std::vector<std::vector<int>>& vec, int ax, int ay, int bx, int by) {
    int w = vec[0].size();
    int h = vec.size();
    if (vec[ay][ax] == true && vec[by][bx] == true) {
        return uf.same(ay * w + ax, by * w + bx);
    }
    else {
        return false;
    }
}


int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int h, w, q;
    std::cin >> h >> w;
    std::cin >> q;
    std::vector<std::vector<int>> vec(h, std::vector<int>(w, false));
    UnionFind uf(h * w);

    for (int i = 0; i < q; ++i) {
        int query;
        std::cin >> query;
        if (query == 1) {
            int y, x;
            std::cin >> y >> x;
            --y; --x;
            vec[y][x] = true;
            unite(uf, vec, x, y);
        }

        else if (query == 2) {
            int ay, ax, by, bx;
            std::cin >> ay >> ax >> by >> bx;
            --ay; --ax; --by; --bx;
            if (check(uf, vec, ax, ay, bx, by)) {
                std::cout << "Yes" << std::endl;
            }
            else {
                std::cout << "No" << std::endl;
            }
        }
    }
}