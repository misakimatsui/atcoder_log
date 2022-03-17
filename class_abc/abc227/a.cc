#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

std::tuple<bool, int, int> search(int a, int b, int predict) {
    for (int a2 = 0;; ++a2) {
        for (int b2 = 0; b2 <= a2; ++b2) {
            int val = 4 * a2 * b2 + 3 * a2 + 3 * b2;
            std::cout << a2 << "," << b2 << predict << " " << val << std::endl;
            if (val == predict) {
                return {true, --a2, --b2};
            }
            else if (predict < val) {
                return {false, --a2, --b2};
            }
        }
    }
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    long int n; 
	std::cin >> n;
    std::vector<int> vec(n);

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        vec[i] = num;
    }
    std::sort(vec.begin(), vec.end());
    int a = 0;
    int b = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        auto [is_ok, a2, b2] = search(a, b, vec[i]);
        a = a2;
        b = b2;
        if (!is_ok) {
            ++ans;
        }
    }
    std::cout << ans << std::endl;
}