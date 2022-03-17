#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, c;
    std::cin >> n >> c;
    std::vector<pair<ll,ll>> vec;
    for (int i = 0; i < n; ++i) {
        ll a, b, c;
        std::cin >> a >> b >> c;
        vec.push_back({a, c});
        vec.push_back({b+1, -c});
    }
    std::sort(vec.begin(), vec.end());
    ll sum = 0;
    ll ans = 0;
    ll left = vec[0].first;
    for (const auto& x : vec) {
        ans += sum * (x.first - left);
        sum += x.second;
        left = x.first;
    }
    cout << ans << endl;
}