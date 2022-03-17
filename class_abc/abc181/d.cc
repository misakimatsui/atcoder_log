#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string str;
    std::cin >> str;

    std::vector<char> vec;
    for (auto x : str) {
        vec.push_back(x);
    }

    do {
        std::string s;
        for (auto x : vec) {
            s += x;
        }
        long int val = stol(s);
        if (val % 8 == 0) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    } while (next_permutation(vec.begin(), vec.end()));

    std::cout << "No" << std::endl;
    return 0;
}