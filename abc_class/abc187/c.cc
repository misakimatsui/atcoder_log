#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;
//解けた20分
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<std::string> vec(n);
    for (auto& x : vec) {
        std::string str;
        std::cin >> str;
        std::string rev(str.rbegin(), str.rend());
        x = rev;
    }
    std::sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] + "!" == vec[i+1]) {
            std::string rev(vec[i].rbegin(), vec[i].rend());
            std::cout << rev << std::endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
}