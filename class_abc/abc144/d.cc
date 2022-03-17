#include <bits/stdc++.h>

using namespace std;
using ll = long int;

int main(void) {
    double a, b, x;
    std::cin >> a >> b >> x;
    double area = (x / (a * a)) * a;
    double h = (2 * area) / b;
    double cc = sqrt(h * h + b * b);
    double hoge = ( 2 * area) / cc;
    cout << 90.0 - (180 - (180 / M_PI * asin(hoge / h) + 90.0)) << endl;

}