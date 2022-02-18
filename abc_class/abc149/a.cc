#include <iostream>
#include <vector>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    long int a, b, k; 
	std::cin >> a >> b >> k;
    if (a < k) {
        b -= k - a;
        a = 0;
    }
    else {
        a -= k;
    }
    if (b < 0) {
        b = 0;
    }
	std::cout << a << " " << b << std::endl;
}