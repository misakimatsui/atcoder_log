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

    int n;
    std::cin >> n;
    std::vector<char> first(n);
    std::vector<char> second(n);
    int q;
    for (int i = 0; i < n; ++i) {
        std::cin >> first[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> second[i];
    }
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int t, a, b;
        std::cin >> t >> a >> b;
        --a;
        --b;
        if (t == 1) {
            int amod = a % n;
            int adiv = a / n;
            int bmod = b % n;
            int bdiv = b / n;
            if (adiv == 0 && bdiv == 0) {
                std::swap(first[amod], first[bmod]);
            }
            else if (adiv == 1 && bdiv == 0) {
                std::swap(second[amod], first[bmod]);
            }
            else if (adiv == 0 && bdiv == 1) {
                std::swap(first[amod], second[bmod]);
            }
            else if (adiv == 1 && bdiv == 1) {
                std::swap(second[amod], second[bmod]);
            }
        }
        else if (t == 2) {
            std::swap(first, second);
        }
    }
    for (auto x : first) {
        std::cout << x;
    }
    for (auto x : second) {
        std::cout << x;
    }
    std:cout << std::endl;
    
}