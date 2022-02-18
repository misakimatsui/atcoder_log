#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <climits>

using namespace std;
//30m

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long int n, m;
    std::cin >> n >> m;
    std::vector<long int> vec(m+1, 0);
    for (long int i = 1; i < vec.size(); ++i) {
        std::cin >> vec[i];
    }
    vec.push_back(n + 1);
    std::sort(vec.begin(), vec.end());
    long int min = INT_MAX;
    for (long int i = 1; i < vec.size(); ++i) {
        long int val = vec[i] - vec[i-1] - 1;
        if (0 < val) {
            min = std::min(min, val);
        }
    }
    long int ans = 0;
    for (long int i = 1; i < vec.size(); ++i) {
        long int val = vec[i] - vec[i-1] - 1;
        if (min <= val) {
            long int div = val / min;
            long int mod = val % min;
            if (0 < mod) {
                ++div;
            }
            ans += div;
        }
    }
    std::cout << ans << std::endl;
}