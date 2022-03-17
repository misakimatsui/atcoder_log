#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    long int N, A, B, P, Q, R, S;
    std::cin >> N >> A >> B;
    std::cin >> P >> Q >> R >> S;


    std::vector<std::string> vec(Q - P + 1, std::string(S - R + 1, '.'));
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) {
            int y = i + P;
            int x = j + R;
            //if (x - A == y - B || x - A && B - y || A - x == B - y || A - x && y - B) {
                vec[i][j] = '#';
        }
    }
    for (auto y : vec) {
        std::cout << y << std::endl;
    }
}