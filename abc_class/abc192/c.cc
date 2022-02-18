#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

long int g1(long int n) {
    std::vector<int> vec;
    std::string tmp = std::to_string(n);
    for (int i = 0; i < tmp.size(); ++i) {
        vec.push_back(tmp[i] - '0');
    }
    std::sort(vec.begin(), vec.end(), [](int l, int r) {return l > r;});
    std::string s;
    for (auto x : vec) {
        s += std::to_string(x);
    }
    return std::stoi(s);
}

long int g2(long int n) {
    std::vector<int> vec;
    std::string tmp = std::to_string(n);
    for (int i = 0; i < tmp.size(); ++i) {
        vec.push_back(tmp[i] - '0');
    }
    std::sort(vec.begin(), vec.end());
    std::string s;
    for (auto x : vec) {
        s += std::to_string(x);
    }
    return std::stoi(s);

}

long int ff(long int n, long int cnt) {
    if (cnt == 0) {
        return n;
    }
    else {
        return ff(g1(n) - g2(n), cnt - 1);
    }
}


int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;
    std::cout << ff(n, k) << std::endl;

}