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

    long int n, q;
    std::cin >> n >> q;
    std::vector<long int> vec(n);
    for (long int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }
    auto it = vec.begin();
    long int idx = 0;
    long int aa = 0;
    std::multimap<long int , long int> mp;
    while (it != vec.end()) {
        if (1 < *it - idx) {
            aa += *it -idx -1;
        }
        mp.insert(std::make_pair(aa, *it));
        idx = *it;
        ++it;
    }

    for (long int i = 0; i < q; ++i) {
        long int k;
        std::cin >> k;
        auto it = mp.lower_bound(k);
        if (it != mp.end()) {
            std::cout << it->second - (it->first + 1 - k) << std::endl;
        }
        else {
            --it;
            std::cout << it->second + (k - it->first) << std::endl;
        }
    }
}