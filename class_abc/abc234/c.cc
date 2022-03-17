#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <bitset>


int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    long int n;
    std::cin >> n;

    std::vector<long int> vec;
    for (long int i = 0; n > 0; i++) {
        if (1 == n % 2) {
            vec.push_back(2);
        }
        else {
            vec.push_back(0);
        }
        n = n / 2;
    }
    for (long int i = vec.size()-1;  0 <= i; --i ) {
        std::cout << vec[i];
    }
    std::cout << std::endl;
}
