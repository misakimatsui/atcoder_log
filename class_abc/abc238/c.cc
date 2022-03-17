#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main(void) {
    long int n;
    std::cin >> n;

    long int right = 1;
    long int left = 9;

    mint ans = 0;
    long int pow10 = 1;

    while (right <= n) {
        mint from = right;
        mint to  = std::min(left, n);
        mint nn = to - from + 1;
        ans += (nn * (1 + nn)) / 2;

        pow10 *= 10;
        left = pow10 * 9 + left;
        right *= 10;
    }
    std::cout << ans.val() << std::endl;
}