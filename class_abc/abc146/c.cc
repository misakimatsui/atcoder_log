#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

//不等式だからダメ？

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    cpp_int a, b, x;
    std::cin >> a >> b >> x;
    cpp_int digit = (x.str()).size();
    cpp_int pow10 = 1;
    cpp_int val = 9;
    cpp_int ans = 0;
    for (cpp_int i = 1; i <= digit; ++i) {
        cpp_int nn = (x - b * (i)) / a;
        if (nn.str().size() == i) {
            if (1 <= nn && nn <= 10000000000) {
                ans = max(ans, nn);
            }
            else if (1000000000 < nn) {
                ans = max(ans, cpp_int{1000000000});
            }
        }
        else {
            if (val < nn) {
                ans = max(ans,  min(val, cpp_int{1000000000}));
            }
        }
		pow10 *= 10;
		val = pow10 * 9 + val;
    }
    std::cout << ans << std::endl;
}