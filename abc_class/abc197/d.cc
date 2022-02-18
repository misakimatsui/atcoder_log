#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;


int getDistance(double x, double y, double x2, double y2) {
    double distance = std::sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
    return (int) distance;
}

double getRadian(double x, double y, double x2, double y2) {
    double radian = std::atan2(y2 - y,x2 - x);
    return radian;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::pair<double, double> f;
    std::pair<double, double> m;
    std::cin >> f.first >> f.second >> m.first >> m.second;
    double radian = getRadian(f.first, f.second, m.first, m.second);
    double distance = getDistance(f.first, f.second, m.first, m.second);
    double degree = radian * 180.0 / M_PI;
    std::cout << (f.first + m.first) / 2 << std::endl;
    std::cout << (f.second + m.second) / 2 << std::endl;


    degree += 360.0 / n;
    std::cout << degree << std::endl;
    radian = degree * M_PI / 180.0;
    std::cout << 1.5 + std::cos(radian) * distance / 2 << std::endl;
    std::cout << 1.5 + std::sin(radian) * distance / 2 << std::endl;


}