#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

//解けず
using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> veca;
    std::vector<std::pair<int, int>> vecb;
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        veca.push_back(std::make_pair(a, a - b));
        vecb.push_back(std::make_pair(a - b, a));
    }
    std::sort(veca.begin(), veca.end(), [](auto l, auto r) { return l > r; });
    std::sort(vecb.begin(), vecb.end(), [](auto l, auto r) { return l > r; });
    int val = 0;
    int cnt = veca.size();
    auto ait = veca.begin();
    auto bit = vecb.begin();

    while(cnt) {
        if (val <= 0) {
            val += ait->first;
            ait->first = 0;
            ait->second = 0;
            ++ait;
        }
        else {
            val -= bit->first;
            if (bit->first != 0 && bit->second != 0) {
                bit->first = 0;
                bit->second = 0;
                --cnt;
            }
            ++bit;
        }
    }



}