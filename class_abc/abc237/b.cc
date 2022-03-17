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

    long int h, w;
    std::cin >> h >> w;
    std::vector<std::vector<long int>> vec(h, std::vector<long int>(w, 0));
    for (long int y = 0; y < h; ++y) {
        for (long int x = 0; x< w; ++x) {
            std::cin >> vec[y][x];
        }
    }
    for (long int x = 0; x< w; ++x) {
        for (long int y = 0; y < h; ++y) {
            std::cout << vec[y][x] << " ";
        }
        std::cout << std::endl;
    }
}