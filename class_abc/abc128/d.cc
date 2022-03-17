#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n, m;
    std::set<ll> st;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        st.insert(x);
    }
    for (int i = 0; i < m; ++i) {
        ll b, c;
        cin >> b >> c;
        auto it = st.lower_bound(c);
        int idx = distance(st.begin(), it);

    }
}