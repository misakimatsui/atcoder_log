#include <bits/stdc++.h>
using namespace std;
using ll = long int;

int main(void) {
    ll l, k;
    std::cin >> l >> k;
    ll max = min(2019L, k - l);
    ll ans = (l * (l + 1)) % 2019;
    for (ll i = l; i <= l + max; ++i) {
        for (ll j = i+1; j <= l + max; ++j) {
            ans = min(((i % 2019) * (j % 2019)) % 2019, ans);
        }
    }
    cout << ans << endl;
}