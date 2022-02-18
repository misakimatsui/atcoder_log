#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>


std::vector<char> DectoN(unsigned int dec, unsigned int n, unsigned int digit) {

    static const char coef[36] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    std::vector<char> vec;
    if (n > 36 || n < 2) {
        return vec;
    }
    vec.assign(digit, '0');
    
    unsigned int i = 0;
    while (dec > 0 || i < digit) {
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

    int val;
    std::cin >> val;
    std::vector<int> vec;
    while(0 < val) {
        int num = val % 10;
        vec.push_back(num);
        val /= 10;
    }
    std::sort(vec.begin(), vec.end());

    int base_number = 2;
    int n = vec.size();

    int seki = 0;
    for (int bit = 0; bit < std::pow(base_number, n); ++bit) {
        auto v = DectoN(bit, base_number, n);
        std::map<int, std::vector<int>> ans;
        for (int i = 0; i < n; ++i) {
                ans[toInt(v[i])].push_back(vec[i]);
        }

        int tmp = 1;
        for (int i = 0; i < base_number; ++i) {
            int vv = 0;
            for (int j = ans[i].size()-1; 0 <= j; --j) {
                vv += ans[i][j] * std::pow(10, j);
            }
            tmp *= vv;
        }
        seki = std::max(seki, tmp);
    }
    std::cout << seki << std::endl;
}