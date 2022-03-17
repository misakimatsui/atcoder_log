#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, k;
    std::cin >> n >> k;
    --k;

    std::vector<std::pair<int, int>> vec;
    for (int i = 0; i < n; ++i) {
        int a, b, c; 
        std::cin >> a >> b >> c;
        vec.push_back(std::make_pair(a+b+c, i));
    }
    std::sort(vec.begin(), vec.end(), [](auto &left, auto &right)
              { return left.first > right.first; });

    std::vector<std::string> ans(n);
    for (int i = 0; i < vec.size(); ++i) {
        auto itr = std::lower_bound(vec.begin(), vec.end(),
                                    std::pair<int, int>(vec[i].first + 300, -1),
                                    [](const auto &l, const auto &r)
                                    { return l.first > r.first; });
        std::size_t pos = std::distance(vec.begin(), itr);
        if (pos <= k) {
            ans[vec[i].second] = "Yes";
        }
        else {
            ans[vec[i].second] = "No";
        }
    }
    for (auto x : ans) {
        std::cout << x << std::endl;
    }
}
