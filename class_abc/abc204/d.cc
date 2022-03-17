#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long int n;
    std::cin >> n;
    std::vector<long int> vec(n);
    long int max = 0;
    for (long int i = 0; i < n; ++i) {
        std::cin >> vec[i];
        max += vec[i];
    }
    std::vector<long int> dp(max+3, -1);
    std::vector<long int> tmp(max+3, -1);
    long int min = max;
    long int ans = 0;
    for (auto x : vec) {
        std::copy(dp.begin(), dp.end(), tmp.begin());
        for (long int i = max; 0 <= i; --i) {
            if (i + x < dp.size() && dp[i + x] != -1) {
                tmp[i] = x + dp[i + x];
                long int diff = std::abs(std::abs(max - i) - i);
                if(diff <= min) {
                    min = diff;
                    ans = i;
                }
            }
        }
        tmp[max - x] = x;
        long int diff = std::abs(std::abs(max - x) - x);
        if(diff <= min) {
            min = diff;
            ans = x;
        }
        std::copy(tmp.begin(), tmp.end(), dp.begin());

    }
    std::cout << std::max(max - ans, ans) << std::endl;
}