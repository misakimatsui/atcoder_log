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

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> b(n);
    for (auto& x : a) {
        std::cin >> x;
    }
    for (auto& x : b) {
        std::cin >> x;
    }
    std::vector<std::vector<int>> vec(n);
    std::vector<std::vector<int>> p(3010, std::vector<int>(3010, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = a[i]; j <= b[i]; ++j) {
            vec[i].push_back(j);
            p[i][j] = 1;
        }
    }
    for (int j = 1; j < 3010; ++j) {
        p[0][j] = (p[0][j] + p[0][j-1]) % 998244353;
    }

    for (int i = 1; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) {
            p[i][vec[i][j]] = p[i-1][vec[i][j]];
        }
        for (int j = 1; j < 3010; ++j) {
            p[i][j] = (p[i][j] + p[i][j-1]) % 998244353;
        }
    }
    std::cout << p[vec.size()-1][3010-1] << std::endl;
}