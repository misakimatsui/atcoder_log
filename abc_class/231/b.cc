#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> map(0, 100010);
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	std::cin >> n >> m; 
	std::vector<std::vector<int>> bit(n+1);

	int a, b;
	std::cin >> a >> b;
	map[1] = a;
	map[2] = b;
	int idx = 3;
	for (int i = 1; i < m; ++i) {
		int a, b;
		auto a_pos = std::find(map.begin(), map.end(), a);
		auto b_pos = std::find(map.begin(), map.end(), b);
		if (a_pos == map.end() && b_pos ==map.end()) {
			++idx;
			map[idx] = a;
			++idx;
			map[idx] = b;
		}
		if (a_pos != map.end() 
		else {
		}
		std::cin >> a >> b;
	}
	std::cout << "Yes" << std::endl;
}

