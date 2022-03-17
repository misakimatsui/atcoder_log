#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    std::cin >> n;
    ll a_sum = 0;
    std::vector<ll> vec(n);
    for (auto& x : vec) {
        ll a, b;
        std::cin  >> a >> b;
        x = 2 * a + b;
        a_sum += a;
    }
    ll ans = 0;
    ll b_sum = 0;
    std::sort(vec.begin(), vec.end(), std::greater<ll>());
    auto it = vec.begin();
    while (b_sum <= a_sum) {
            b_sum += *it;
            ++it;
            ans++;
    }
    std::cout << ans << std::endl;
}