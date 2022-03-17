#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<ll> vec(n);
    for (auto& x : vec) {
        cin >> x;
    }
    std::vector<ll> ans(n, 0);
    ans.back() = vec.back();
    for (int i = 0; i < n-1; ++i) {
        if (i % 2 == 0) {
            ans.back() -= vec[i];
        }
        else {
            ans.back() += vec[i];
        }
    }
    ans[0] += 2 * (vec[n-1] - ans[n-1] / 2);
    for (int i = n - 1; 0 < i; --i) {
        ans[i-1] = 2 * (vec[i-1] - ans[i] / 2);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] <<  " ";
    }
    cout << endl;
}