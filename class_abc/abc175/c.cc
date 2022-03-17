#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll x, k, d;
    std::cin >> x >> k >> d;
    ll mod = x % d;
    ll div = x / d;
    ll ans = 0;
    if (div < k) {
        ans = mod + (k - div) * d;
    }
    else {

    }
    cout << ans << endl;
}