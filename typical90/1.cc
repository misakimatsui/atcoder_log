#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

bool solve(long int thresh, const std::vector<long int>& vec, long int k, long int l) {
    long int cnt = 0;
    long int sum = 0;
    for (auto x : vec) {
        if (thresh <= x - sum && thresh <= l - x) {
            cnt++;
            sum = x;
        }
    }
    return (k <= cnt ? true : false);
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long int n, l, k;
    std::cin >> n >> l;
    std::cin >> k;
    std::vector<long int> vec(n);
    for (auto& x : vec) {
        std::cin >> x;
    }

    long int left = -1;
    long int right = l + 1;
    long int cnt = 0;
    while (right - left > 1) {
        long int mid = left + (right - left) / 2;
        if (solve(mid, vec, k, l)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    std::cout << left << std::endl;

}