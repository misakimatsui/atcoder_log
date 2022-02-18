#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

//38分
using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long int n;
    std::cin >> n;
    std::vector<long int> vec(n);
    for (long int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }
    std::sort(vec.begin(), vec.end());

    std::vector<long int> diff(n, 0);
    for (int i = 1; i < n; ++i) {
        diff[i] = std::abs(vec[i] - vec[i-1]);
    }
    for (int i = 1; i < n; ++i) {
        long int val = diff[i-1] + (i * diff[i]);
        diff[i] = val;
    }
    long int ans = 0;
    for (auto x : diff) {
        ans += x;
    }
    std::cout << ans << std::endl;
}