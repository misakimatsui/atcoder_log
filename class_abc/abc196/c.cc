#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

unsigned GetDigit(unsigned num){
    return std::to_string(num).length();
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long int n;
    std::cin >> n;

    bool isloop = true;
    long int mul = 1;
    long int cnt = 0;
    while(isloop) {
        long int digit = GetDigit(mul);
        long int sum = mul * (std::pow(10, digit)) + mul;
        if (sum <= n) {
            cnt++;
        }
        else {
            isloop = false;
        }
        mul++;
    };
    std::cout << cnt << std::endl;
}