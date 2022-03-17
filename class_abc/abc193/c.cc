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
    std::set<long int> mp;
    long int mul = 2;
    while (true) {
        long int v = static_cast<long int>(log(n) / log(mul));
        if (v < 2) {
            break;
        }
        for (long int i = 2; i <= v; ++i) {
            long int val = std::pow(mul, i);
            mp.insert(val);
        }
        mul++;
    }
    std::cout << n - mp.size() << std::endl;
}