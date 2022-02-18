#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

std::vector<int> enum_div(int n)
{
    std::vector<int> ret;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i != 1 && i * i != n)
            {
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}

int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x;
    std::cin >> n >> x;
    std::vector<std::vector<int>> vec;
    for (int i = 0; i < n; ++i)
    {
        int l;
        std::cin >> l;
        std::vector<int> tmp(l);
        for (int j = 0; j < l; ++j)
        {
            int num;
            std::cin >> num;
            tmp[j] = num;
        }
        vec.push_back(tmp);
    }

    std::map<int, int> ans;
    auto divs = enum_div(x);
    for (auto val : divs)
    {
        ans.insert(std::make_pair(val, 0));
    }
    ans.insert(std::make_pair(x, 0));

    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) {
            int val = (vec[i][j]);
            auto it = ans.find(val);
            if (it != ans.end()) {
                int tmp = ans[val];
                ans[x / val] += tmp + 1;
            }
        }
    }
    int answer = 0;
    for (auto X : ans) {
        if (X.second == n) {
            ++answer;
        }
    }
    std::cout << answer << std::endl;
}