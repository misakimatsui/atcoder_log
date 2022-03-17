#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

std::vector<int> decode(unsigned int dec, unsigned int digit) {
    unsigned int n = 2;
    std::vector<int> vec;
    vec.assign(digit, '0');
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

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    std::vector<vector<int>> vec(n);
    for (int i =0; i < m; ++i) {
        int k, s;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> s;
            --s;
            vec[s].push_back(i);
        }
    }
    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }

    int ans = 0;
    for (int bit = 0; bit < pow(2, n); ++bit) {
        auto v = decode(bit, n);
        vector<int> tmp(m, 0);
        for (int i = 0; i < vec.size(); ++i) {
            if (v[i] == 1) {
                for (int j = 0; j < vec[i].size(); ++j) {
                    tmp[vec[i][j]] = (tmp[vec[i][j]] + 1) % 2;
                }
            }
        }
        if (p == tmp) {
            ans++;
        }
    }
    cout << ans << endl;
}