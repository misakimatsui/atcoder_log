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

    int h, w, n;
    std::cin >> h >> w >> n;
    std::vector<std::pair<int, int>> xvec(n); //x, n
    std::vector<std::pair<int, int>> yvec(n); //y, n
    for (int i = 0; i < n; ++i) {
        int y, x;
        std::cin >> y >> x;
        xvec[i].first = x;
        xvec[i].second = i;
        yvec[i].first = y;
        yvec[i].second = i;
    }

    std::sort(xvec.begin(), xvec.end());
    std::sort(yvec.begin(), yvec.end());
    int xcnt(0), ycnt(0);
    int xprev(-1), yprev(-1);
    for (int i = 0; i < n; ++i) {
        if (xprev != xvec[i].first) {
            xcnt++;
        }
        xprev = xvec[i].first;
        xvec[i].first = xcnt;
    }
    for (int i = 0; i < n; ++i) {
        if (yprev != yvec[i].first) {
            ycnt++;
        }
        yprev = yvec[i].first;
        yvec[i].first = ycnt;
    }
    std::sort(xvec.begin(), xvec.end(), [](auto a, auto b){ return a.second < b.second;});
    std::sort(yvec.begin(), yvec.end(), [](auto a, auto b){ return a.second < b.second;});

    for (int i = 0; i < n; ++i) {
        std::cout << yvec[i].first << " " << xvec[i].first  << std::endl;
    }
}