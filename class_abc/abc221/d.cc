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


//イモス法のデータの持ち方

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	ll n;
	std::cin >> n;
	std::vector<std::pair<ll, ll>> imos;
	for (int i = 0; i < n; ++i) {
		ll a, b;
		std::cin >> a >> b;
		--a; --b;
		imos.push_back(std::make_pair(a, 1));
		imos.push_back(std::make_pair(a + b + 1, -1));
	}
	std::sort(imos.begin(), imos.end());
	std::map<ll, ll> mp;
	int cnt = 0;
	for (int i = 0; i < imos.size(); ++i) {
		cnt += imos[i].second;
		mp[cnt] += imos[i+1].first - imos[i].first;
	}
	for (int i = 1; i <= n; ++i) {
		std::cout << mp[i] << " ";
	}
	std::cout << std::endl;
}