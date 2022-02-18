#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <atcoder/all>


using mint = atcoder::modint1000000007;
using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int k;
    std::cin >> k;
    std::vector<mint> dp(k+1);
    dp[0] = 1;
    if (k % 9 != 0) {
        std::cout << 0 << std::endl;
        return 0;
    }
    for (int i = 1; i <= k; ++i) {
        int min = std::min(i, 9);
        for (int j = 1; j <= min; ++j) {
            dp[i] += dp[i - j];
        }
    }
    std::cout << dp[k].val() << std::endl;
}