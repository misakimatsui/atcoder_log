#include <bits/stdc++.h>
#include <atcoder/all>

using namespace atcoder;
using namespace std;
using ll = long int;
using mint = modint1000000007;
const int inf = INT_MAX;

std::vector<int> decode(unsigned int dec, unsigned int digit) {
    unsigned int n = 2;
    std::vector<int> vec;
    vec.assign(digit, 0);
    unsigned int i = 0;
    while (dec > 0 && i < digit) {
        unsigned int digit_num = dec % n;
        vec[i] = digit_num;
        dec = dec / n;
        i++;
    }
    std::reverse(vec.begin(), vec.end());
    return vec;
}

int checkcount(const vector<int>& vec, int k) {
    int i = find(vec.begin(), vec.end(), 1) - vec.begin();
    int tmpidx = i;
    int cnt = 0;
    int bcnt = 0;
    for (; i < vec.size(); ++i) {
        if (vec[i] == 1) {
            bcnt++;
            if (1 < i - tmpidx) {
                cnt++;
            }
            tmpidx = i;
        }
    }
    return bcnt == k ? cnt + 1 : 0;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;
    std::vector<mint> ans(k+1, 0);

    for (int bit = 1; bit < pow(2, n); ++bit) {
        auto v = decode(bit, n);
        ans[checkcount(v, k)]++;
    }
    for (int i = 1; i < ans.size(); ++i) {
        cout << ans[i].val() << endl;
    }
}