#include <bits/stdc++.h>

using namespace std;
using ll = long int;
//10minutes
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    std::cin >> n;
    std::vector<pair<ll, ll>> vec(n);
    for (auto& x : vec) {
        cin >> x.first >> x.second;
    }
    sort(vec.begin(), vec.end(), [](auto& l, auto& r) { return l.second < r.second;});
    ll sum = 0;
    for (ll i = 0; i < vec.size(); ++i) {
        sum += vec[i].first;
        if (vec[i].second < sum) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}