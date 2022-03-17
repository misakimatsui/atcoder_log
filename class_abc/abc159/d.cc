#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;
//40分
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::map<int, int> mp;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        vec.push_back(a);
        mp[a]++;
    }
    ll sum = 0;
    for (const auto& [a, cnt] : mp) {
        sum += 1LL * cnt * (cnt - 1) / 2;
    }

    for (const auto& x : vec) {
        ll tmp = 1LL * max(0, mp[x]) * max(0, mp[x] - 1) / 2;
        ll tmp2 = 1LL * max(0, mp[x] - 1) * max(0, mp[x] - 2) / 2;
        cout << sum - (tmp - tmp2) << endl;
    }
}