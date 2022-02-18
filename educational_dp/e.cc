#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long long;
const ll inf =  1LL << 60;
ll max_value = 100010;

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	ll n, weight;
	std::cin >> n >> weight;
	std::vector<std::pair<ll, ll>> vec(n); //weight, value
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[i].first >> vec[i].second;
	}
	std::vector<ll> dp(max_value, inf);
	std::vector<ll> tmp(max_value);
	dp[0] = 0;
	for (const auto& [w, v] : vec) {
		std::copy(dp.begin(), dp.end(), tmp.begin());
		for (int i = 0; i <= max_value; ++i) {
			ll idx = std::min(max_value, i + v);
			if (tmp[i] + w < dp[idx]) {
				dp[idx] = tmp[i] + w;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < max_value; ++i) {
		if (dp[i] <= weight) {
			ans = i;
		}
	}
	std::cout << ans << std::endl;
}