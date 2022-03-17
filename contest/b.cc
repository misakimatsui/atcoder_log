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
    std::vector<ll> avec(n);
    std::vector<ll> bvec(n);
    for (auto& x : avec) {
        cin>> x;
    }
    for (auto& x : bvec) {
        cin>> x;
    }
    ll ans1 = 0;
    for (int i = 0; i < n; ++i) {
        if (avec[i] == bvec[i]) {
            ans1++;
        }
    }
    ll ans2 = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (avec[i] == bvec[j]) {
                ans2++;
            }
        }
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
}