#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    cpp_int x, y;
    std::cin >> x >> y;
    cpp_int sum = 0;
    int cnt = 1;
    for (int i = 1; i <= y; i+=2) {
        sum += cnt;
        cnt++;
    }
    cout << sum << endl;
    cout << x * y << endl;
}