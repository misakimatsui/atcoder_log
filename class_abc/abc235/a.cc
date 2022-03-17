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

    std::string s;
    std::cin >> s;

    int cnt = 0;
    int sum = 0;
    for (int cnt = 0; cnt < 3; ++cnt) {
        for (int i = 0; i < 3; ++i) {
            int tmp = s[(cnt + i) % 3] - '0';
            sum += tmp * std::pow(10, 2 - i);
        }
    }
    std::cout << sum << std::endl;
}
