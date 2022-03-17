#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

using namespace std;
using ll = long int;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll a, b, n;
    ll x = 0;
    std::cin >> a >> b >> n;
    if (b <= n) {
        x = b - 1;
    }
    else {
        x = n;
    }
    cout <<(a * x) / b - a * (x / b) << endl;
}
