// 全bit探索 2進数
#include <iostream>
#include <vector>
#include <algorithm>


/* 10進数decをn進数に変換して結果をansに格納する */
std::vector<char> DectoN(unsigned int dec, unsigned int n) {

    static const char coef[36] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    std::vector<char> vec;
    if (n > 36 || n < 2) {
        /* 対応しているのは2進数から36進数まで */
        return vec;
    }
    
    unsigned int i(0);
    unsigned int digit_num;
    while (dec > 0) {
        digit_num = dec % n;
        vec.push_back(coef[digit_num]);
        dec = dec / n;
        i++;
    }
    std::reverse(vec.begin(), vec.end());
    return vec;
}


int main(void) {

    int n = 4;
    std::vector<int> vec{1,2,3,4};



    //10進数をX進数に変換
    auto v = DectoN(7, 3);
    for (auto X : v) {
        std::cout << X;

    }
    std::cout << std::endl;

    for (int bit = 0; bit < (1<<n); ++bit) {
        std::vector<int> L, R;
        for (int i = 0; i < n; ++i) {
            std::cout << bit << std::endl;
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                L.push_back(vec[i]);
            }
            else {
                R.push_back(vec[i]);

            }
        }

        std::cout << bit << ": { ";
        for (int i = 0; i < L.size(); ++i) {
            std::cout << L[i] << " ";
        }
        std::cout << "}";

        std::cout << " { ";
        for (int i = 0; i < R.size(); ++i) {
            std::cout << R[i] << " ";
        }
        std::cout << "}";
        std::cout << '\n';

    }

}