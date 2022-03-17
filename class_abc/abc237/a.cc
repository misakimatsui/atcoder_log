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
    if (std::pow(-2, 31) <= n && n < std::pow(2, 31)) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" <<std::endl;
    }
}