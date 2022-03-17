#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>


long double getDistance(long double x, long double y, long double x2, long double y2) {
    long double distance = std::sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
    return distance;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n;
    std::cin >> n;

    std::vector<std::pair<long double, long double>> vec;

    for (int i = 0; i < n; ++i) {
        long double x, y;
        std::cin  >> x >> y;
        vec.push_back(std::make_pair(x, y));
    }
    long double ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                ans = std::max(ans, getDistance(vec[i].first, vec[i].second, vec[j].first, vec[j].second));
            }
        }
    }
    std::cout << std::fixed << std::setprecision(15) << ans << std::endl;

}
