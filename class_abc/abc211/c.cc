#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long int;
using mint = atcoder::modint1000000007;
const int inf = INT_MAX;


int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;
    std::string chokudai = "chokudai";
    std::vector<std::vector<mint>> dp(chokudai.size() + 1, std::vector<mint>(s.size() + 1, 0));
    for (int i = 0; i < dp[0].size(); ++i) {
        dp[0][i] = 1;
    }
    //for (int i = 0; i < dp.size(); ++i) {
    //    dp[i][0] = 1;
    //}
    for (int i = 1; i <= chokudai.size(); ++i) {
        for (int j = 1; j <= s.size(); ++j) {
            if (chokudai[i-1] == s[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    std::cout << dp[chokudai.size()][s.size()].val() << std::endl;
}