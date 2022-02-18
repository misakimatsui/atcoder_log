#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;
using ll = long int;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    std::cin >> n;
    std::vector<ll> vec(n);
    double value = 0;
    for (auto& x : vec) {
        int val;
        std::cin >> val;
        x = val;
        value += val;
    }
    value /= 10.0f;
    for (int i = 0; i < n; ++i) {
        vec.push_back(vec[i]);
    }
    vec.insert(vec.begin(), 0);
    for (int i = 1; i < vec.size(); ++i) {
        vec[i] += vec[i-1];
    }

    ll right = 0;
    for (int l = 0; l < vec.size(); ++l) {
        while (right < vec.size()) {
            if (vec[right] - vec[l] == value) {
                std::cout << "Yes" << std::endl;
                return 0;
            }
            else if (vec[right] - vec[l] < value) {
                right++;
            }
            else {
                break;
            }
        }
    }
    std::cout << "No" << std::endl;

}