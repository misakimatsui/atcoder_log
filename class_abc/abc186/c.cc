#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;
//10分

std::vector<char> decode(unsigned int dec, unsigned int n) {

    static const char coef[36] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    std::vector<char> vec;
    if (n > 36 || n < 2) {
        // 対応しているのは2進数から36進数まで
        return vec;
    }

    unsigned int i = 0;
    while (dec > 0) {
        unsigned int digit_num = dec % n;
        vec.push_back(coef[digit_num]);
        dec = dec / n;
        i++;
    }
    std::reverse(vec.begin(), vec.end());
    return vec;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        std::string str = std::to_string(i);
        bool isseven = false;

        for (auto x : str) {
            if (x == '7') {
                isseven = true;
            }
        }
        auto v = decode(i, 8);
        for (auto x : v) {
            if (x == '7') {
                isseven = true;
            }
        }
        if (!isseven) {
            ++cnt;
        }
    }
    std::cout << cnt << std::endl;
}