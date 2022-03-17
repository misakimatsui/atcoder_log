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

    long int n;
    std::cin >> n;
    std::vector<long int> vec(n);
    for (auto& x : vec) {
        std::cin >> x;
    }
    long int ans = n * (n - 1) / 2;

    std::sort(vec.begin(), vec.end());
    vec.push_back(-1);
    long int cnt = 1;
    for (long int i = 1; i < vec.size(); ++i) {
        if (vec[i-1] == vec[i]) {
            cnt++;
        }
        else {
            ans -= cnt * (cnt - 1) / 2;
            cnt = 1;
        }
    }
    std::cout << ans << std::endl;
}