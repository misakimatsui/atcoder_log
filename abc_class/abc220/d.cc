#include <iostream>
#include <vector>

long int dp[100100][10];

long long mod = 998244353;

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    long int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    //init
    dp[0][vec[0]] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (0 < dp[i-1][j]) {
                int seki = (vec[i] * j) % 10;
                int sum = (vec[i] + j) % 10;
                (dp[i][seki] += dp[i-1][j]) %= mod;
                (dp[i][sum] += dp[i-1][j]) %= mod;
            }
        }
    }
    for (int j = 0; j < 10; ++j) {
        std::cout << dp[n-1][j] << std::endl;
    }




}