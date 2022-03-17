#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/range/adaptors.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<std::string> left, right;
    std::string tmp = "0";
    char c;
    for (int i = 1; i <= n; ++i) {
        std::cin >> c;
        if (c == 'L') {
            right.push_back(tmp);
            tmp = std::to_string(i);
        }
        else {
            left.push_back(tmp) ;
            tmp = std::to_string(i);
        }
    }
    if (c == 'L') {
        left.push_back(tmp);
    }
    else {
        right.push_back(tmp);
    }
    for (const auto& x : left) {
        std::cout << x << " ";
    }
    for (const auto& x : boost::adaptors::reverse(right)) {
        std::cout << x << " ";
    }
 
    std::cout << std::endl;
}