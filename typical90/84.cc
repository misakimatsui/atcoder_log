#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;
using ll = long int;

// ランレングス圧縮
// 条件を満たす個数よりも条件を満たさない個数の方が数えやすい場合余事象を考える
// 問題を言い換える
// 区間の組み合わせ n(n+1) / 2
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    std::string str;
    std::cin >> n;
    std::cin >> str;
    std::vector<std::pair<char, ll>> vec;
    {
        char c = '-';
        for (int i = 0; i < str.size(); ++i) {
            if (c != str[i]) {
                vec.push_back(std::make_pair(str[i], 1));
            }
            else {
                vec.back().second++;
            }
            c = str[i];
        }
    }
    ll ans = n * (n + 1) / 2;
    for (const auto& [_, cnt] : vec) {
        ans -= cnt * (cnt + 1) / 2;
    }
    std::cout << ans << std::endl;
}