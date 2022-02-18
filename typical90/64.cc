#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n ,q;
    std::cin >> n >> q;
    std::vector<int> vec(n);
    for (auto& x : vec) {
        std::cin >> x;
    }
    long int sum = 0;
    for (int i = 1; i < vec.size(); ++i) {
        sum += std::abs(vec[i] - vec[i-2]);
    }
    for (int i = 0; i < q; ++i) {
        int l, r, v;
        std::cin >> l >> r >> v;
        --l; --r;
        if (l != 0)  {
            abs(v) * cnt;
        }
        if (r != (n - 1)) {
        }
    }
}