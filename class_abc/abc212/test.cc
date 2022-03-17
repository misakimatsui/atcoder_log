#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <climits>

using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    std::vector<int> b(m);
    for (auto& x : a) {
        std::cin >> x;
    }
    for (auto& x : b) {
        std::cin >> x;
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    int min = INT_MAX;
    for (auto x : a) {
        auto it = std::lower_bound(b.begin(), b.end(), x);
        if (it != b.end()) {
            min = std::min(std::abs(*it - x), min);
            if (0 < std::distance(b.begin(), it)) {
                --it;
                min = std::min(std::abs(*it - x), min);
            }
        }
        else {
            min = std::min(std::abs(b.back() - x), min);
        }
    }
    std::cout << min << std::endl;
}