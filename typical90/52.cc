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

    int n;
    std::cin >> n;

    mint ans = 1;
    std::vector<std::vector<int>> vec(n, std::vector<int>(6, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            int a;
            std::cin >> a;
            vec[i][j] = a;
        }
    }
    for (int i = 0; i < n; ++i) {
        mint tmp = 0;
        for (int j = 0; j < 6; ++j) {
            tmp += vec[i][j];
        }
        ans *= tmp;
    }
    std::cout << ans.val() << std::endl;
}