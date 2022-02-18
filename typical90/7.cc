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

    ll n, q;
    std::cin >> n;
    std::vector<ll> vec(n);
    for (auto& v : vec) {
        std::cin >> v;
    }
    std::sort(vec.begin(), vec.end());

    std::cin >> q;
    for (ll i = 0; i < q; ++i) {
        ll b;
        std::cin >> b;
        ll left = 0;
        ll right = vec.size() - 1;
        while (right - left > 1) {
            ll mid = (right + left) / 2;
            if (vec[mid] < b) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        std::cout << std::min(std::abs(vec[left] - b), std::abs(vec[left+1] - b)) << std::endl;
    }
}