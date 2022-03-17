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
    std::vector<int> vec(n);
    for (auto& x : vec) {
        cin >> x;
    }
    sort(vec.begin(), vec.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int r = lower_bound(vec.begin(), vec.end(), vec[j] + vec[i]) - vec.begin();
            ans += max(0, r - (j + 1));
        }
    }
    cout << ans << endl;
}