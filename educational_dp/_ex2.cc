#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

// コイントスをN回行うとき、表または、裏がK回以上連続ででる確立を求めよ

using namespace std;
using ll = long int;
const int inf = INT_MAX;
const int MAX_N = 10;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, K;
    std::cin >> N >> K;
    std::vector<std::vector<double>> dp(MAX_N, std::vector<double>(MAX_N, 0.0));
    dp[1][1] = 1.0;

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            if (j + 1 < K) {
                dp[i+1][j+1] += dp[i][j] / 2.0;
            }
            dp[i+1][1] += dp[i][j] / 2.0;
        }
    }
    double sum = 0.0;
    for (int i = 0; i < K; ++i) {
        sum += dp[N][i];
    }
    std::cout << 1 - sum << std::endl;
}