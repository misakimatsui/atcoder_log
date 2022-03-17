#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c, x;
    std::cin >> a >> b >> c >> x;
    double ans = 0.0;
    if (x <= a) {
        cout << fixed << setprecision(15) << 1.0 << endl;
    }
    else if (a < x && x <= b) {
        cout << fixed << setprecision(15) << c / (1.0 * (b - a)) << endl;
    }
    else {
        cout << fixed << setprecision(15) << 0.0 << endl;
    }
}