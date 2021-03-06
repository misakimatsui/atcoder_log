#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, X, Y;
    std::cin >> N;
    std::cin >> X >> Y;
    std::vector<std::vector<int>> dp(Y+1, std::vector<int>(X+1, 99999));
    dp[0][0] = 0;
    for (int i = 0; i < N; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::vector<std::vector<int>> tmp(Y+1, std::vector<int>(X+1, 99999));
        std::copy(dp.begin(), dp.end(), tmp.begin());
        for (int y = 0; y < Y+1; ++y) {
            for (int x = 0; x < X+1; ++x) {
                int xx = x + a;
                int yy = y + b;
                xx = std::min(xx, X);
                yy = std::min(yy, Y);
                dp[yy][xx] = std::min(dp[yy][xx], tmp[y][x] + 1);
            }
        }
    }
    if (dp[Y][X] == 99999) {
        std::cout << "-1" << std::endl;
    }
    else {
        std::cout << dp[Y][X] << std::endl;
    }
}
