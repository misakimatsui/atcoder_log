#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::string s;
    int k;
    std::cin >> s;
    std::cin >> k;
    std::vector<char> vec;
    for (int i = 0; i < s.size(); ++i) {
        vec.push_back(s[i]);
    }
    std::sort(vec.begin(), vec.end());
    int cnt = 0;
    do {
        cnt++;
        if (cnt == k) {
            for (auto x : vec) {
                std::cout << x;
            }
            std::cout << std::endl;

        }

    } while(std::next_permutation(vec.begin(), vec.end()));
}