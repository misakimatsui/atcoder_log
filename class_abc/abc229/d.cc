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
    int k;
    std::cin >> s;
    std::cin >> k;
    std::vector<int> vec(s.size()+1);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '.') {
            vec[i+1] = vec[i] + 1;
        }
        else {
            vec[i+1] = vec[i];
        }
    }
    int ans = 0;
    int r = 0;
    for (int l = 0; l < vec.size(); ++l) {
        while (r < vec.size()) {
            if (std::abs(vec[r] - vec[l]) <= k) {
                ans = std::max(ans, r - l);
            }
            else {
                break;
            }
            ++r;
        }
    }
    std::cout << ans << std::endl;
}