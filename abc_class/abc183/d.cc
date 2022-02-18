#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <numeric>

using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, w;
    std::cin >> n >> w;
    std::vector<std::pair<int, int>> vec;
    for (int i = 0; i < n; ++i) {
        int s, t, p;
        std::cin >> s >> t >> p;
        vec.push_back(std::make_pair(s, p));
        vec.push_back(std::make_pair(t, -p));
    }
    std::sort(vec.begin(), vec.end());
    long int cnt = 0;
    for (auto x : vec) {
        cnt += x.second;
        if (w < cnt) {
            std::cout << "No" <<std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
}