#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

double getDistance(double x, double y, double x2, double y2) {
    return std::sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int r, x, y;
    std::cin >> r >> x >> y;
    float dis = getDistance(0, 0 , x, y);
    int cnt = dis / r;
    float mod = std::fmod(dis, r);
    int ans = 0;
    if (cnt == 0) {
        ans = 2;
    }
    else if (0 < mod) {
        ans = cnt + 1;
    }
    else {
        ans = cnt;
    }
    std::cout << ans << std::endl;
}