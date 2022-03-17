#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

int main() {
	ll n;
	cin >> n;

	mint ans = 0;
	ll pow10 = 1;
	while (pow10 <= n) {
		mint from = pow10;
		mint to = std::min(pow10 * 10 - 1, n);
        mint nn = to - from + 1;
        ans += (nn * (1 + nn)) / 2;
		pow10 *= 10;
	}
	cout << ans.val() << endl;
}