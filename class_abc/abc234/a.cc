#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long int f(long int t) {
    return std::pow(t, 2) + 2 * t + 3;

}
int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    long int t;
    std::cin >> t;
    std::cout << f(f(f(t) + t) + f(f(t))) << std::endl;

}
