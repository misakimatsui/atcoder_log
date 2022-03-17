#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <array>
#include <map>


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, a;
	std::cin >> n >> a;
	std::vector<std::vector<float>> vec(n, std::vector<float>(n, 0));

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int val;
		std::cin >> val;
		vec[i][i] = val;
		if (val == a) {
			ans++;
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		int y = i;
		int x = i + 1;
		float val1 = vec[y][y] + vec[x][x];
		float val2 = (vec[x][x] + vec[y][x - 1]); 
		if ((val / 2.0f) == a) {
			ans++;
		}
	}
	std::cout << ans << std::endl;


}


