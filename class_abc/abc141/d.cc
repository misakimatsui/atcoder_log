#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;
//10分
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    priority_queue<ll> que;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        que.push(x);
    }
    for (int i = 0; i < m; ++i) {
        ll tmp = que.top();
        que.pop();
        que.push(tmp / 2);
    }
    ll ans = 0;
    while(!que.empty()) {
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
}