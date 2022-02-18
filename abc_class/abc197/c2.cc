#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 20;

    // {0, 1, ..., n-1} の部分集合の全探索
    int cnt = 0;
    for (int bit = 0; bit < (1<<(n - 1)); ++bit) {
        vector<int> S;
        for (int i = 0; i < n - 1; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                std::cout << "1";
                S.push_back(i);
            }
            else {
                std::cout << "0";
            }
        }
        std::cout << std::endl;
    }
}