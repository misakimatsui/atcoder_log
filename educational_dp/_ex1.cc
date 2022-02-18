#include <bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;

// https://compro.tsutaj.com//archive/180220_probability_dp.pdf
// 出た目の和の確立

// 1から6までの整数が等確立にでるさいころが1つある。
// これをN回降るとき、出た目の和がK回以上になる確立を求めよ

using namespace std;
using ll = long int;
const int inf = INT_MAX;
const int MAX_N = 2010;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, K;
    std::cin >> N >> K;
    std::vector<std::vector<double>> dp(MAX_N, std::vector<double>(6 * MAX_N, 0.0));
    dp[0][0] = 1.0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= K; ++j) {
            for (int k = 1; k <= 6; ++k) {
                int val = std::min(j + k, K);
                dp[i+1][val] += dp[i][j] / 6.0;
            }
        }
    }
    std::cout << dp[N][K] << std::endl;
}