#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;
	std::map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		mp[a]++;
	}
	long int ans = 0;
	for (int i = -200; i <= 200 ; ++i) {
		for (int j = i; j <= 200; ++j) {
			if (i != j) {
				long int cnt = 1LL * mp[i] * mp[j];
				ans += 1LL * (i - j) * (i - j) * cnt;
			}
		}
	}
	std::cout << ans << std::endl;
}