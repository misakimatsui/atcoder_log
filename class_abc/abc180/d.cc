#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    cpp_int x, y, a, b;
    std::cin >> x >> y >> a >> b;

    cpp_int ans = 0;
    while (true) {
      if (a * x > b + x ||  a * x >= y) {
        break;
      }
      x *= a;
      ans++;
    }
    ans += (y - 1 - x) / b;
    std::cout << ans << std::endl;
}