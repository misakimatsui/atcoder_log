#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n = 5000;
    ll sum = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            for (int l = j - i; l <= j; ++l) {
                sum++;
            }
        }
    }
    cout << sum << endl;
}