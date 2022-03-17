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
    std::vector<std::pair<double, double>> vec(n);
    for (int i = 0; i < n; ++i) {
        int t;
        double l, r;
        std::cin >> t >> l >> r;
        switch(t) {
            case 1 :
                break;
            case 2 :
                r -= 0.1;
                break;
            case 3 :
                l += 0.1;
                break;
            case 4 :
                l += 0.1;
                r -= 0.1;
                break;
        };
        vec[i] = std::make_pair(l, r);
    }
    std::sort(vec.begin(), vec.end());
    int ans = 0;
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = i+1; j < vec.size(); ++j) {
            if (vec[j].first <= vec[i].second) {
                ++ans;
            }
        }
    }
    std::cout << ans << std::endl;
}