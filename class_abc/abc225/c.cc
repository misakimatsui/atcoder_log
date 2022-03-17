#include <vector>
#include <iostream>
#include <algorithm>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    long int n, m;
    long int tmp; 
    std::cin >> n >> m;
    std::vector<long int> vec(m);
    for (long int j = 0; j < m; ++j) {
            std::cin >> vec[j];
    }
    for (long int j = 1; j < m; ++j) {
           if (vec[j-1] + 1 !=  vec[j]) {
               std::cout << "No" << std::endl;
               return 0;
           }
    }
    for (long int i = 1; i < n; ++i) {
        for (long int j = 0; j < m; ++j) {
            long int b;
            std::cin >> b;
            if (vec[j] + 7 != b) {
               std::cout << "No" << std::endl;
               return 0;
            }
            vec[j] = b;
        }
    }
    std::cout << "Yes" << std::endl;
}