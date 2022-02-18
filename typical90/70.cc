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

    ll n;
    std::cin >> n;
    std::vector<ll> xvec(n);
    std::vector<ll> yvec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> xvec[i] >> yvec[i];
    }
    std::sort(xvec.begin(), xvec.end());
    std::sort(yvec.begin(), yvec.end());
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += std::abs(xvec[i] - xvec[n/2]);
        ans += std::abs(yvec[i] - yvec[n/2]);
    }
    std::cout << ans << std::endl;
}