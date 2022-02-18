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
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int ans = 2147483647;
    for (int i = 0; i < m; ++i) {
        int val;
        std::cin >> val;
        auto it = std::lower_bound(a.begin(), a.end(), val);
        ans = std::min(ans, std::abs(val - *it));
        if (it != a.begin()) {
            ans = std::min(ans, std::abs(val - *prev(it)));
        }
    }
    std::cout << ans << std::endl;
}

       
       