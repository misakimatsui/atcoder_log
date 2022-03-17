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
    std::vector<int> s(n);
    std::vector<int> t(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
    }
    auto t_itr = std::min_element(t.begin(), t.end());
    auto pos = std::distance(t.begin(), t_itr);


    for (int i = 1; i < n; ++i) {
        int idx = (pos + i) % n;
        int pidx = (pos + i - 1) % n;
        t[idx] = std::min(t[idx], t[pidx] + s[pidx]);
    }
    for (int i = 0; i < n; ++i) {
        std::cout << t[i] << std::endl;
    }

}