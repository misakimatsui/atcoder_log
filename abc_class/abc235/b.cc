#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;
    std::map<int, std::vector<int>> mp;
    for (int i = 1; i <= n; ++i) {
        int val;
        std::cin >> val;
        mp[val].push_back(i);
    }
    std::vector<int> ans;
    for (int i = 0; i < q; ++i) {
        int x, k;
        std::cin >> x >> k;
        
        if(0 < mp[x].size()&& k -1 < mp[x].size()) {
            std::cout << mp[x][k-1] << std::endl;

        }
        else {
            std::cout << "-1" << std::endl;

        }
    }
}