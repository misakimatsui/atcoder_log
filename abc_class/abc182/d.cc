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
    std::vector<long int> sum(n);
    std::copy(vec.begin(), vec.end(), sum.begin());
    for (long int i = 1; i < vec.size(); ++i) {
        sum[i] += sum[i-1];
    }
    for (long int i = 1; i < vec.size(); ++i) {
        sum[i] += sum[i-1];
    }
    auto it  = std::max_element(sum.begin(), sum.end());
    long int idx = std::distance(sum.begin(), it);


    long int s = *it;
    long int max = s;
    for (long int i = 0; i <= idx+1; ++i) {
        s += vec[i];
        max = std::max(max, s);

    }
    std::cout << max << std::endl;
}