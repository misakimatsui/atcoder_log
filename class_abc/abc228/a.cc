#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    float s, t, x;
    std::cin >> s >> t >> x;

    x += 0.5;
    if (s <= t) {
        if (s <= x && x <= t) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    else {
        if ((s <= x && x <= 24) || (0 <= x && x <= t)) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl;
}
