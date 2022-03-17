#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, k;
    std::cin >> n >> k;
    ll ans = 0;
    for (ll i = 2*n; 2 <= i; --i) {
        ll tmp = i - k;
        if (2 <= tmp && tmp <= 2*n) {
            ll sum = ((i - 1) - (max(0L, (i - n) - 1) * 2));
            ans += sum * ((tmp - 1) - (max(0L, (tmp - n) - 1) * 2));
        }
    }
    cout << ans << endl;
}