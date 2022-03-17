#include <bits/stdc++.h>
#include <atcoder/all>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using namespace atcoder;

using mint = modint998244353;
using ll = long int;
const int inf = INT_MAX;


int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    vector<mint> vec{0,2,3,3,3,3,3,3,3,2};
    int n;
    std::cin >> n;

    for (int i = 3; i <= n; ++i) {
        vector<mint> tmp{0,0,0,0,0,0,0,0,0,0};
        for (int j = 1; j < 10; ++j) {
            for (int k = j-1; k <= j+1; ++k) {
                if (1 <= k && k <= 9) {
                    tmp[j] += vec[k];
                }
            }
        }
        swap(vec, tmp);
    }
    mint sum = 0;
    for (auto x : vec) {
        sum += x;
    }
    cout << sum.val() << endl;
}