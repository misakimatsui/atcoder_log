#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    std::map<char, char> mp;
    for (int i = 1; i <= 26; ++i) {
        char c;
        std::cin >> c;
        mp[c] = static_cast<char>(96 + i);
    }
    int n;
    std::cin >> n;
    std::vector<std::pair<std::string, std::string>> ans;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        std::string f;
        for (int j = 0; j < s.size(); ++j) {
            f += mp[s[j]];
        }
        ans.push_back(std::make_pair(f, s));
    }
    std::sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i].second << std::endl;
    }



}