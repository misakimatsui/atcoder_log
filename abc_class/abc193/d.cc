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


int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll k;
    std::cin >> k;
    std::vector<ll> mp(10, k);
    ll sval(0), tval(0);
    std::vector<ll> svec(10, 0), tvec(10, 0); //count
    {
        std::string s, t;
        std::cin >> s >> t;
        for (int i = 0; i < 4; ++i) {
            svec[s[i] - '0']++;
            tvec[t[i] - '0']++;
            mp[s[i]-'0']--;
            mp[t[i]-'0']--;
        }
        for (int i = 1; i <= 9; ++i) {
            sval += i * std::pow(10, svec[i]);
            tval += i * std::pow(10, tvec[i]);
        }
    }
    double win = 0;
    for (int i = 1; i <= 9; ++i) { //s
        for (int j = 1; j <= 9; ++j) { //t
            std::vector<ll> vv(10);
            std::copy(mp.begin(), mp.end(), vv.begin());
            vv[i]--; vv[j]--;
            bool isok = std::all_of(vv.begin(), vv.end(), [](ll x) { return 0 <= x;});
            if (isok) {
                ll stmp = sval - i * std::pow(10, svec[i]) + i * std::pow(10, svec[i]+1);
                ll ttmp = tval - j * std::pow(10, tvec[j]) + j * std::pow(10, tvec[j]+1);
                if (ttmp < stmp) {
                    win += mp[i] * (mp[j] - (i == j));
                }
            }
        }
    }

    std::cout << double(win) / (9 * k - 8) / (9 * k - 9) << std::endl;

}