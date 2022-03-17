#include <bits/stdc++.h>

using namespace std;
using ll = long int;


map<ll, int> enumpr(ll n) {
	map<ll, int> V;
	for (ll i = 2; i * i <= n; i++) while (n % i == 0) V[i]++, n /= i;
	if (n > 1) V[n]++;
	return V;
}

int main(void) {
    long int n;
    cin >> n;

    long int ans = 0;
    const auto& mp = enumpr(n);
    for (auto [f, s] : mp) {
        for (ll i = 1, sum = 0; sum <= s; ++i) {
            sum += i;
            if (sum <= s) {
                ans++;
            }
        }
    }
    cout << ans << endl;

}