#include <bits/stdc++.h>

using namespace std;
using ll = long int;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    std::cin >> n;
    std::vector<ll> vec(n);
    for (auto& x : vec) {
        cin >> x;
    }
    sort(vec.begin(), vec.end(), std::greater<ll>());
    std::priority_queue<ll> que;
    ll ans = 0;
    que.push(vec[0]);
    que.push(vec[1]);
    ans += vec[0];
    for (int i = 2; i < vec.size(); ++i) {
        ans += que.top();
        que.push(vec[i]);
        que.pop();
    }
    cout << ans << endl;
}