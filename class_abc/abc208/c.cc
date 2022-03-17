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

    long int n, k;
    std::cin >> n >> k;
    long int ans = k / n;
    long int idx = k % n;
    vector<long int> vec(n);
    vector<long int> p(n);
    for(int i = 0; i < n; ++i) {
        long int n;
        cin >> n;
        vec[i] = n;
        p[i] = n;
    }
    std::sort(p.begin(), p.end());
    for (int i = 0; i < n; ++i) {
        auto it = std::find(p.begin(), p.end(), vec[i]);
        auto pos = std::distance(p.begin(), it);
        if (pos < idx) {
            std::cout << ans + 1 << std::endl;
        }
        else {
            std::cout << ans << std::endl;
        }
    }
}