#include <bits/stdc++.h>

using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto& x : vec) {
        std::cin >> x;
    }
    int ans = 0;
    for (int l = 0; l < vec.size(); ++l) {
        int min = INT_MAX;
        for (int r = l; r < vec.size(); ++r) {
            min = std::min(min, vec[r]);
            ans = std::max(ans, min * (r - l + 1));
        }
    }
    std::cout << ans << std::endl;
}