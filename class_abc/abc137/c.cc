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
    map<string, ll> mp;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        mp[str]++;
    }
    ll ans = 0;
    for (const auto& [_, cnt] : mp) {
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << endl;
}