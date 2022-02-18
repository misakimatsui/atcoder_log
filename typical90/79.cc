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

    int h, w;
    std::cin >> h >> w;
    std::vector<std::vector<int>> avec(h, std::vector(w, 0));
    std::vector<std::vector<int>> bvec(h, std::vector(w, 0));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cin >> avec[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cin >> bvec[i][j];
        }
    }
    ll cnt = 0;
    for (int i = 0; i < h-1; ++i) {
        for (int j = 0; j < w-1; ++j) {
            int diff = 0;
            diff = bvec[i][j] - avec[i][j];
            avec[i][j] += diff;
            avec[i + 1][j] += diff;
            avec[i][j + 1] += diff;
            avec[i + 1][j + 1] += diff;
            cnt += std::abs(diff);
        }
    }
    if (avec != bvec) {
        std::cout << "No" << std::endl;
    }
    else {
        std::cout << "Yes" << std::endl;
        std::cout << cnt << std::endl;
    }
}