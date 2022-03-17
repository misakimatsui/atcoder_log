#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<int> vec(n, 0);
    for (auto& x : vec) {
        char c;
        cin >> c;
        if (c == 'R') {
            x = 1;
        }
    }
    vector<int> rvec;
    vector<int> wvec;
    for (int i = 0; i < n; ++i) {
        if (vec[i] == 1) {
            rvec.push_back(i);
        }
        else {
            wvec.push_back(i);
        }
    }
    std::sort(rvec.begin(), rvec.end(), std::greater<int>());
    int ans = 0;
    int l = 0; int r = 0;
    for (int i = 0; i < min(rvec.size(), wvec.size()); ++i) {
        if (wvec[i] < rvec[i]) {
            l = wvec[i];
            r = rvec[i];
            ans++;
        }
    }
    bool iswhite = false;
    for (int i = l+1; i < r; ++i) {
        if (vec[i] == 0) {
            iswhite = true;
        }
        else if (iswhite) {
            ans++;
        }
    }
    cout << ans << endl;
}