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

    std::map<ll, ll> a;
    std::map<ll, ll> b;
    std::map<ll, ll> c;
    for (int i = 0; i < n; ++i) {
        ll val;
        std::cin >> val;
        a[val%46]++;
    }
    for (int i = 0; i < n; ++i) {
        ll val;
        std::cin >> val;
        b[val%46]++;
    }
    for (int i = 0; i < n; ++i) {
        ll val;
        std::cin >> val;
        c[val%46]++;
    }
//    std::map<ll, ll> ans;
//    for (const auto& [av, acnt] : a) {
//        for (const auto& [bv, bcnt] : b) {
//            for (const auto& [cv, ccnt] : c) {
//                ans[av+bv+cv] += acnt * bcnt * ccnt;
//            }
//        }
//    }
//    std::cout << ans[46] << std::endl;


    ll ans = 0;
    for (const auto& [av, acnt] : a) {
        for (const auto& [bv, bcnt] : b) {
            for (const auto& [cv, ccnt] : c) {
                if ((av + bv + cv) % 46 == 0) {
                    ans += acnt * bcnt * ccnt;
                }
            }
        }
    }
    std::cout << ans << std::endl;

}