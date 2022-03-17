#include <bits/stdc++.h>

using namespace std;
using ll = long int;
const int inf = INT_MAX;

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
//10minutes
int main(void) {
    ll a, b, c, d;
    std::cin >> a >> b >> c >> d;
    ll cnum = b / c - (a - 1) / c;
    ll dnum = b / d - (a - 1) / d;
    ll cdnum = b / lcm(c, d) - (a - 1) / lcm(c, d);
    cout << (b - (a - 1)) - (cnum + dnum - cdnum) << endl;
}