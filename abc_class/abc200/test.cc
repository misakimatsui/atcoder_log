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

    long int n;
    std::cin >> n;
    std::map<long int, long int> mp;
    for (int i = 0; i < n; ++i) {
        long int val;
        std::cin >> val;
        mp[val % 200]++;
    }
    long int ans = 0;
    auto it = mp.begin();
    while (it != mp.end()) {
        ans += (it->second * (it->second - 1)) / 2;
        ++it;
    }
    std::cout << ans << std::endl;
}