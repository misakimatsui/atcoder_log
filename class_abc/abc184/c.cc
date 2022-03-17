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

    long int r, c, r2, c2;
    std::cin >> r >> c >> r2 >> c2;
    if (r == r2 && c == c2) {
        std::cout << 0 << std::endl;
        return 0;
    }
    else if (std::abs(r - r2) + std::abs(c - c2) <= 3) {
        std::cout << 1 << std::endl;
        return 0;
    }
    else if (r + c == r2 + c2 || r - c == r2 - c2) {
        std::cout << 1 << std::endl;
        return 0;
    }

    else {
        if ((r2 + r + c2 + c) % 2 == 0)  {
            std::cout << 2 << std::endl;
            return 0;
        }
        else {
            if (r + c == r2 + 1 + c2 || r - c == r2 + 1 - c2) {
                std::cout << 2 << std::endl;
                return 0;
            }
            else if (r + c == r2 - 1 + c2 || r - c == r2 - 1 - c2) {
                std::cout << 2 << std::endl;
                return 0;
            }
            else {
                std::cout << 3 << std::endl;
                return 0;
            }
        }
    }

}