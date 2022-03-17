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

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> b(n);
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i];
    }

    std::map<int, int> d;
    auto it = c.begin();
    while(it != c.end()) {
        int idx = *it;
        if (idx - 1 < b.size()) {
            d[b[idx - 1]]++;
        }
        ++it;
    }

    long int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        ans += d[a[i]];
    }
    std::cout << ans << std::endl;
}