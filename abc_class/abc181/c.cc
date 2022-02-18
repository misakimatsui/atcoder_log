#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;
    std::map<char, int> mp;
    for (auto c : s) {
        mp[c]++;
    }
    for (int i = 1; i < 1000; ++i) {
        std::string s(std::to_string(i));
        std::map<char, int> tmp = mp;
        bool isok = true;
        for (auto c : s) {
            mp[c]--;
            if (mp[c] < 0) {
                isok = false;
            }
        }
        if (isok && i % 8 == 0) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl;
}