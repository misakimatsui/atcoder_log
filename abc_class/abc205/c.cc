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

    long int a, b, c;
    std::cin >> a >> b >> c;
    int de = c % 2;
    if (0 == c % 2) {
        a = abs(a);
        b = abs(b);
    }
    if (a == b) {
        std::cout << '=' << std::endl;
    }
    else if (a < b) {
        std::cout << '<' << std::endl;
    }
    else {
        std::cout << '>' << std::endl;
    }

}