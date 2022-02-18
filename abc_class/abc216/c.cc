#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);


    unsigned long int n;
    std::cin >> n;

    std::vector<char> vec;
    while(n != 0) {
        if (n % 2 == 1) {
            --n;
            vec.push_back('A');
        }
        else {
            n /= 2;
            vec.push_back('B');
        }
    }
    for (int i = vec.size() - 1; 0 <= i; --i) {
        std::cout << vec[i];
    }

}