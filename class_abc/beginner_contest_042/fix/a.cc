#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, n2, n3;
	std::cin >> n >> n2 >> n3; 
	
	int num5 = 0;
	int num7 = 0;
	int sum = 0;
	if ( n == 5 || n == 7) sum += n;
	if ( n2 == 5 || n2 == 7) sum += n2;
	if ( n3 == 5 || n3 == 7) sum += n3;

	if (sum == 17) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	} 
}


