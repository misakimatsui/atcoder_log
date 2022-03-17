#include <iostream>
#include <vector>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int a, b, k; 
	std::cin >> a >> b >> k;
    for (int i = 0; i < k; ++i) {
        if (0 < a) {
            --a;
        }
        else if (0 < b) {
            --b;
        }
    }

	std::cout << a << " " << b << std::endl;
}