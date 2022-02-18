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

    int h,w;
    std::cin >> h >> w;
    std::vector<std::vector<int>> vec(h+1, std::vector<int>(w+1, 0));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            char c;
            std::cin >> c;
            if ('#' == c) {
                vec[i][j] = -1;
            }
        }
    }
    vec[0][1] = 1;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (vec[i][j] == -1) {
                vec[i][j] = 0;
            }
            else {
                vec[i][j] = (vec[i-1][j] + vec[i][j-1]) % static_cast<int>(std::pow(10, 9) + 7);
            }
        }
    }
    std::cout <<  vec[h][w] << std::endl;
}