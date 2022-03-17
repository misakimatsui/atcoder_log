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

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, k;
    std::cin >> n >> k;
    std::vector<ll> vec(n);
    for (auto& x : vec) {
        std::cin >> x;
    }
    std::priority_queue<ll, std::vector<ll>, greater<ll>> que;
    for (ll i = 0; i < k; ++i) {
        que.push(vec[i]);
    }
    std::cout << que.top() << std::endl;
    for (ll i = k; i < n; ++i) {
        que.push(vec[i]);
        que.pop();
        std::cout << que.top() << std::endl;
    }

}