#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll v, a, b, c;
    std::cin >> v >> a >> b >> c;
    int cnt = 0;
    while(true) {
        cnt = cnt % 3;
        if (cnt == 0) {
            v -= a;
            if (v < 0) {
                std::cout << "F" << endl;
                return 0;
            }
        }
        else if (cnt == 1) {
            v -= b;
            if (v < 0) {
                std::cout << "M" << endl;
                return 0;
            }
        }
        else  {
            v -= c;
            if (v < 0) {
                std::cout << "T" << endl;
                return 0;
            }
        }
        cnt++;
    } 
}