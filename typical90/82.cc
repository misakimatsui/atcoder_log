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

using ll = long int;
using mint = atcoder::modint1000000007;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll L, R;
    std::cin >> L >> R;
    mint l = L;
    mint r = r;
    mint ans = (r - l + 1) * (l + r) / 2;
    std::cout << ans.val() << std::endl;
}