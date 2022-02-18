#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;


long int cnt = 0;
long int n, x;

void dfs(std::vector<std::vector<long int>>& vec, long int depth, long int seki) {
    for (auto v : vec[depth]) {
        long int val = seki / v;
        long int check = seki % v;
        if (depth + 1 == n) {
            if (check == 0 && val == 1) {
                ++cnt;
            } 
        }
        if (1+depth < n){
            if (check == 0 && 0 < val) {
                dfs(vec, 1+depth, val);
            }
        }
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> x;
    std::vector<std::vector<long int>> vec(n);

    for (int i = 0; i < n; ++i) {
        long int l;
        std::cin >> l;
        for (int j = 0; j < l; ++j) {
            long int a;
            std::cin >> a;
            vec[i].push_back(a);
        }
    }
    dfs(vec, 0, x);
    std::cout << cnt << std::endl;
}