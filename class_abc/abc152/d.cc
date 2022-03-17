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
    vector<std::vector<int>> vec(10, vector<int>(10, 0));
    for (int i = 1; i <= n; ++i) {
        int btm = i % 10;
        int top = -1, x = i;
        while(0 < x) {
            top = x % 10;
            x /= 10;
        }
        vec[top][btm]++;
    }
    ll ans = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j)  {
            ans += vec[i][j] * vec[j][i];
        }
    }
    cout << ans << endl;
}