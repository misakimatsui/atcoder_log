#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

// dec 変換する値, n 変換する進数, digit 桁数指定
std::vector<char> decode(unsigned int dec, unsigned int n, unsigned int digit) {

    static const char coef[36] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    std::vector<char> vec;
    if (n > 36 || n < 2) {
        // 対応しているのは2進数から36進数まで
        return vec;
    }
    vec.assign(digit, '0');

    unsigned int i = 0;
    while (dec > 0 && i < digit) {
        unsigned int digit_num = dec % n;
        vec[i] = coef[digit_num];
        dec = dec / n;
        i++;
    }
    std::reverse(vec.begin(), vec.end());
    return vec;
}

int toInt(char n) {
    switch(n) {
        case '0': return 0; case '1': return 1; case '2': return 2; case '3': return 3; case '4': return 4;
        case '5': return 5; case '6': return 6; case '7': return 7; case '8': return 8; case '9': return 9;
        case 'A': return 10; case 'B': return 11; case 'C': return 12; case 'D': return 13; case 'E': return 14;
        case 'F': return 15; case 'G': return 16; case 'H': return 17; case 'I': return 18; case 'J': return 19;
        case 'K': return 20; case 'L': return 21; case 'M': return 22; case 'N': return 23; case 'O': return 24;
        case 'P': return 25; case 'Q': return 26; case 'R': return 27; case 'S': return 28; case 'T': return 29;
        case 'U': return 30; case 'V': return 31; case 'W': return 32; case 'X': return 33; case 'Y': return 34;
        case 'Z': return 35;
    }
    return -1;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int base_number = 2;
    ll n, m, x;
    std::cin >> n >> m >> x;
    std::vector<vector<ll>> vec(n, vector<ll>(m, 0));
    vector<ll> cvec(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> cvec[i];
        for (int j = 0; j < m; ++j) {
            cin >> vec[i][j];
        }
    }

    for (int bit = 0; bit < std::pow(base_number, n); ++bit) {
        auto v = decode(bit, base_number, n);
        for (int i = 0; i < v.size(); ++i) {
            if(v[i] == '1') {
                
            }

        }
    }
}