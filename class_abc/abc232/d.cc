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

    int h, w;
    std::cin >> h >> w;
    std::vector<std::vector<int>> vec(h, std::vector<int>(w, -9999999));
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            char c;
            std::cin >> c;
            if (c == '#') {
                vec[y][x] = -1;
            }
        }
    }
    int ans = 1;
    vec[0][0] = 1;
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            if (vec[y][x] != -1 && vec[y][x] != -9999999) {
                if (y+1 < h && vec[y+1][x] != -1) {
                    vec[y+1][x] = std::max(vec[y+1][x], vec[y][x] + 1);
                    ans = std::max(vec[y+1][x], ans);
                }
                if (x+1 < w && vec[y][x+1] != -1) {
                    vec[y][x+1] = std::max(vec[y][x+1], vec[y][x] + 1);
                    ans = std::max(vec[y][x+1], ans);
                }
            }
        }
    }
    std::cout << ans << std::endl;
}