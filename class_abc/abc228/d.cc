#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

const long long n = 1048576;
std::vector<long int> vec(n + 1, -1);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    long int q;
    std::cin >> q;

    for (int i = 0; i < q; ++i) {
        long int t, x;
        std::cin >> t >> x;
        long h = x;
        if (t == 1) {
            while (vec[h % n] != -1) {
                ++h;
            }
            vec[h % n] = x;

        }
        else {
            std::cout << vec[x % n] << std::endl;
        }
    }
}
