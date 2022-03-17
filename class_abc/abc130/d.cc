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
    std::vector<ll> vec(n);
    for (auto & x : vec) {
        cin>> x;
    }
    for (ll i = 1; i < vec.size(); ++i) {
        vec[i] += vec[i-1];
    }
    vec.insert(vec.begin(), 0);
    ll r = 1;
    ll ans  = 0;
    for (ll l = 1; l < vec.size(); ++l) {
        while (r < vec.size() &&  vec[r] - vec[l-1] < k) {
            r++;
        }
        ans += vec.size() - r;
    }
    cout << ans << endl;
}