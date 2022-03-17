#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <numeric>

using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<std::pair<int, int>> vec; //v, w
    std::vector<int> boxs;
    for (int i = 0; i < n; ++i) {
        int w, v;
        std::cin >> w >> v;
        vec.push_back(std::make_pair(v, w));
    }
    std::sort(vec.begin(), vec.end(), [](auto& l, auto& r) { return l.first > r.first; });
    for (int i = 0; i < m; ++i) {
        int w;
        std::cin >> w;
        boxs.push_back(w);
    }
    std::vector<int> p(m);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&boxs](auto& l, auto& r) { return boxs[l] < boxs[r]; });
    for (int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        --l; --r;
        int ans = 0;
        std::vector<int> tmp(m, false);
        for (int j = l; j <= r; ++j) {
            tmp[j] = true;
        }
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                if (tmp[p[k]] == true) continue;
                if (vec[j].second <= boxs[p[k]]) {
                    ans += vec[j].first;
                    tmp[p[k]] = true;
                    break;
                }
            }
        }
        std::cout << ans << std::endl;
    }
}