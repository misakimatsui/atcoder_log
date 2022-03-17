#include <bits/stdc++.h>

using namespace std;
using ll = long int;

int main(void) {
    int n, m;
    std::cin >> n >> m;
    vector<int> dp(n+10, 0);
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        dp[a] = -1;
    }
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (dp[i] != -1 && dp[i+1] != -1) {
            dp[i+1] += dp[i] % 1000000007;
        }
        if (dp[i] != -1 && dp[i+2] != -1) {
            dp[i+2] += dp[i] % 1000000007;
        }
    }
    cout << dp[n] % 1000000007 << endl;
}