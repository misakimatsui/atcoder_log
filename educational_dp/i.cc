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
    std::vector<double> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }
    std::vector<std::vector<double>> dp(n+1, std::vector<double>(n+1, 0.0));
    dp[0][0] = 1.0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i+1][j+1] += dp[i][j] * vec[i];
            dp[i+1][j] += dp[i][j] * (1.0 - vec[i]);
        }
    }
    double ans = 0.0;
    for (int i = n / 2 + 1; i <= n; ++i) {
        ans += dp[n][i];
    }
    cout << std::fixed << std::setprecision(10) << ans << endl;
}