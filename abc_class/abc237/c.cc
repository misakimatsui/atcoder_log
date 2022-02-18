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
    std::vector<char> vec(s.size());
    for (int i = 0; i < s.size(); ++i) {
        vec[i] = s[i];
    }
    std::reverse(vec.begin(), vec.end());

    auto it = vec.begin();
    auto rit = vec.rbegin();
    int cnt = 0;
    while(*it == 'a') {
        if (*it == *rit) {
            cnt++;
            ++rit;
        }
        ++it;
        cnt++;
    }

    int hoge = static_cast<int>((vec.size() - cnt)/2);
    if (hoge < 1) {
        std::cout << "Yes" << std::endl;
        return 0;
    }
    for (int i = 0; i <= static_cast<int>((vec.size() - cnt)/2); ++i) {
        if (*rit != *it) {
            std::cout << "No" << std::endl;
            return 0;
        }
        ++rit;
        ++it;
    }
    std::cout << "Yes" << std::endl;
}