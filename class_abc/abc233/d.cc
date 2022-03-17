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
    std::vector<std::vector<int>> vec(h + 1, std::vector<int>(w + 1, 0));
    for (int y = 1; y <= h; ++y) {
        for (int x = 1; x <= w; ++x) {
            char c;
            std::cin >> c;
            if (c == '#') {
                vec[y][x] = -1;
            }
        }
    }
    for (int y = 1; y <= h; ++y) {
        for (int x = 1; x <= w; ++x) {
            if (vec[y][x] != -1) {
                vec[y][x] = std::max(vec[y - 1][x], vec[y][x - 1]) + 1;
            }
        }
    }
    std::cout << vec[h][w] << std::endl;



}