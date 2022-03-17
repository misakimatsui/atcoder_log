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
                long int y = i + P;
                long int x = j + R;
                if (std::max(1 - A, 1 - B) <= (x - B) && x - B <= std::min(N - A, N - B)
                    //&& std::max(1 - A, 1 - B) <= (y - A) && y - A <= std::min(N - A, N - B)) {
                    && std::max(1 - A, 1 - B) <= (y - A) && y - A <= std::min(N - A, N - B) && x - B == y - A) {
                    vec[i][j] = '#';
                }
                if (std::max(1 - A, B - N) <= (B - x) && B - x <= std::min(N - A, B - 1) 
                    //&& std::max(1 - A, B - N) <= (y - A) && y - A <= std::min(N - A, B - 1)) {
                    && std::max(1 - A, B - N) <= (y - A) && y - A <= std::min(N - A, B - 1) && B - x == y - A) {
                    vec[i][j] = '#';
                }

        }
    }
    for (auto y : vec) {
        std::cout << y << std::endl;
    }
}
