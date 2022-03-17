#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, d;
    std::cin >> n >> d;

    std::vector<std::pair<int, int>> vec;
    --d;

    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        --l;
        --r;
        vec.push_back(std::make_pair(l, r));
    }
    std::sort(vec.begin(), vec.end(), [](auto &left, auto &right) { return left.second < right.second;});

    long int i = vec[0].second + d;
    int ans = 1;
    for (auto x : vec) {
        if (x.first <= i) {
        }
        else {
            i = x.second + d;
            ++ans;

        }
    }

    std::cout << ans << std::endl;
}
