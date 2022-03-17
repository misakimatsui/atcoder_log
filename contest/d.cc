#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
#include<atcoder/all>
using namespace boost::multiprecision;

using namespace std;
using namespace atcoder;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    ll x;
    string str;
    cin >> n >> x;
    cin >> str;
    cpp_int kai = (ll)(log(x) / log(2));
    cpp_int tmp = 1;
    for (ll i = 0; i < kai; ++i) {
        tmp *= 2;
    }
    cpp_int cnt = (x - tmp);

    for (ll i = 0; i < n; ++i) {
        char c = str[i];
        if (c == 'U') {
            if (kai-1 < 0) {
                kai = 0;
            }
            else {
                kai--;
            }
            cnt /= 2;
        }
        else if (c == 'L') {
            kai++;
            cnt = cnt * 2;
        }
        else {
            kai++;
            cnt = cnt * 2 + 1;
        }
    }
    cpp_int ans = 1;
    for (ll i = 0; i < kai; ++i) {
        ans *= 2;
    }
    ans += cnt;
    std::cout << ans << std::endl;
}