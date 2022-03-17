#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

std::vector<int> decode(unsigned int dec, unsigned int digit) {
    unsigned int n = 2;
    std::vector<int> vec;
    vec.assign(digit, '0');
    unsigned int i = 0;
    while (dec > 0 && i < digit) {
        unsigned int digit_num = dec % n;
        vec[i] = digit_num;
        dec = dec / n;
        i++;
    }
    std::reverse(vec.begin(), vec.end());
    return vec;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> vec;

    for (int bit = 1; bit < pow(2, n); ++bit) {
        auto v = decode(bit, n);
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
}