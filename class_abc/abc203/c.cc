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
    std::vector<std::pair<long int, long int>> vec;
    for (long int i = 0; i < n; ++i) {
        long int a, b;
        std::cin >> a >> b;
        vec.push_back(std::make_pair(a, b));
    }
    std::sort(vec.begin(), vec.end());
    
    auto it = vec.begin();
    while(it != vec.end() && it->first <= k) {
        k += it->second;
        ++it;
    };
    std::cout << k << std::endl;
}