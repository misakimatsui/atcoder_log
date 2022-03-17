#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int h, w;
    std::cin >> h >> w;
    std::vector<vector<int>> hvec(h+1, vector<int>{0});
    std::vector<vector<int>> wvec(w+1, vector<int>{0});
    std::vector<vector<bool>> area(h+1, vector<bool>(w+1, true));
    for (int y = 1; y <= h; ++y) {
        for (int x = 1; x <= w; ++x) {
            char c;
            cin >> c;
            if (c == '#') {
                hvec[y].push_back(x);
                wvec[x].push_back(y);
                area[y][x] = false;
            }
        }
    }
    for (int y = 1; y <= h; ++y) {
        for (int x = 1; x <= w; ++x) {
            hvec[y].push_back(w+1);
            wvec[x].push_back(h+1);
        }
    }
    int ans = 0;
    for (int y = 1; y <= h; ++y) {
        for (int x = 1; x <= w; ++x) {
            int result = 0;
            if (area[y][x]) {
                auto it = lower_bound(hvec[y].begin(), hvec[y].end(), x);
                int right = *it;
                int left = *(--it);
                result += (right - left) - 1;
                it = lower_bound(wvec[x].begin(), wvec[x].end(), y);
                right = *it;
                left = *(--it);
                result += (right - left) - 1;
                result -= 1;
            }
            ans = max(ans, result);
        }
    }
    cout << ans << endl;
}