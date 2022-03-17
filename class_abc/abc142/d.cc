#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

vector<long long> enum_div(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i != 0) continue;
        res.push_back(i);
        if (N / i != i) res.push_back(N / i);
    }
    sort(res.begin(), res.end());
    return res;
}

map<ll, int> enumpr(ll n) {
	map<ll, int> V;
	for (ll i = 2; i * i <= n; i++) while (n % i == 0) V[i]++, n /= i;
	if (n > 1) V[n]++;
	return V;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll a, b;
    std::cin >> a >> b;
    auto avec = enum_div(a);
    auto bvec = enum_div(b);
    vector<ll> list;
    std::set_intersection(avec.begin(), avec.end(),
                          bvec.begin(), bvec.end(),
                          std::back_inserter(list));
    sort(list.begin(), list.end());
    auto mp = enumpr(list.back());
    mp[1]++;
    cout << mp.size() << endl;
}