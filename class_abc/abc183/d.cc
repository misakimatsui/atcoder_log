#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, w;
    std::cin >> n >> w;
    std::vector<std::pair<ll, ll>> vec;
    for (int i = 0; i < n; ++i) {
        ll s, t, p;
        std::cin >> s >> t >> p;
        --s; --t;
        vec.push_back(std::make_pair(s, p));
        vec.push_back(std::make_pair(t, -p));
    }
    std::sort(vec.begin(), vec.end(), [](auto& l, auto& r) { 
        if (l.first == r.first) {
            return l.second < r.second;
        }
        else {
            return l.first < r.first;
        }
    });
    ll sum = 0;
    for (int i = 0; i < vec.size(); ++i) {
        sum += vec[i].second;
        if (w < sum) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
}