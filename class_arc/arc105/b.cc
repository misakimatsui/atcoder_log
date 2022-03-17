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
    cin >> n;
    set<ll, std::greater<ll>> rst;
    ll mini = inf;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        rst.insert(x);
        mini = min(mini, x);
    }

    auto it = rst.begin();
    while (true) {
        if (*it == mini) {
            cout << mini << endl;
            break;
        }
        ll maxi = *it;
        ll tmp = maxi - mini;
        rst.insert(tmp);
        mini = min(mini, tmp);
        ++it;
    }
}