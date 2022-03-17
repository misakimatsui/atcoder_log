#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <array>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::vector<std::string> arr;


	int n, k, x, y;
	std::cin >> n >> k >> x >> y;

	int ans;
	if(n - k < 0) {
		ans = n * x;
	}
	else {
		ans = (k * x) + (n - k) * y;
	}

	std::cout << ans << std::endl;
}


