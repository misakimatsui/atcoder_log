#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s;
    int k;
    std::cin >> s;
    std::cin >> k;

    int ans = 0;
    int len = 0;
    int limit = k;
    int i = 0;
    int tmp_i = 0;
    while (i < s.size()) {
        if (s[i] == 'X') {
            ++len;
            ans = std::max(ans, len);
        }
        else if (0 < limit && limit == k) {
            ++len;
            --limit;
            tmp_i = i;
            ans = std::max(ans, len);
        }
        else if (0 < limit) {
            ++len;
            --limit;
            ans = std::max(ans, len);
        }
        else if (limit != k && 0 == limit) {
            len = 0;
            limit = k;
            i = tmp_i;
        }
        else {
            len = 0;
            limit = k;
        }
        ++i;
    }
    std::cout << ans << std::endl;
}
