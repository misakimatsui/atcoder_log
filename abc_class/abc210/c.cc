#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;
using ll = long int;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, k;
    std::cin >> n >> k;
    std::vector<ll> vec(n);
    for (auto& x : vec) {
        std::cin >> x;
    }
    std::map<ll, ll> mp;
    for (ll i = 0; i < k; ++i) {
        mp[vec[i]]++;
    }
    ll ans = mp.size();

    for (ll i = k; i < n; ++i) {
        mp[vec[i]]++;
        mp[vec[i-k]]--;
        if (mp[vec[i-k]] == 0) {
            mp.erase(vec[i-k]);
        }
        ans = std::max(ans, static_cast<ll>(mp.size()));
    }
    std::cout << ans << std::endl;
}