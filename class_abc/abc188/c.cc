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


long int rate[100000];

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<int> vec(std::pow(2, n));
    std::iota(vec.begin(), vec.end(), 1);
    for (auto x : vec) {
        long int n;
        std::cin >> n;
        rate[x] = n;
    }
    while(2 < vec.size()) {
        std::vector<int> tmp;
        for (int i = 1; i < vec.size(); i +=2) {
            if (rate[vec[i-1]] < rate[vec[i]])  {
                tmp.push_back(vec[i]);
            }
            else {
                tmp.push_back(vec[i-1]);
            }
        }
        std::swap(vec, tmp);
    }
    if (rate[vec[0]] < rate[vec[1]]) {
        std::cout << vec[0] << std::endl;
    }
    else {
        std::cout << vec[1] << std::endl;
    }
}