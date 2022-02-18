#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

int ans = -1;


void dfs(const std::vector<std::vector<int>>&  G, int top,  int v, std::vector<bool> seen, int depth) {
    seen[v] = true; 

    if (std::find(G[v].begin(), G[v].end(), top) != G[v].end()) {
        ans = std::max(ans, depth+1);
    }
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; 
        dfs(G, top, next_v, seen, depth+1); 
    }

}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int h, w;
    std::cin >> h >> w;
    std::vector<bool> seen;
    std::vector<std::vector<int>> vec(h, std::vector(w, 0));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char c;
            std::cin >> c;
            if (c == '#') {
                seen.push_back(true);
                vec[i][j] = -1;
            }
            else {
                seen.push_back(false);
                vec[i][j] =  i * w + j;
            }
        }
    }
    std::vector<std::vector<int>> mp(h * w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int idx = i * w + j;
            if (vec[i][j] == -1) continue;
            if (0 <= i - 1 && vec[i-1][j] != -1) {
                mp[idx].push_back(vec[i-1][j]);
            }
            if (i + 1 < h && vec[i+1][j] != -1) {
                mp[idx].push_back(vec[i+1][j]);
            }
            if (0 <= j - 1 && vec[i][j-1] != -1) {
                mp[idx].push_back(vec[i][j-1]);
            }
            if (j + 1 < w && vec[i][j+1] != -1) {
                mp[idx].push_back(vec[i][j+1]);
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int idx = i * w + j;
            if (vec[i][j] != -1) {
                dfs(mp, idx, idx, seen, 0);
            }
        }
    }
    if (ans < 3) {
        std::cout << "-1" << std::endl;
    }
    else {
        std::cout << ans << std::endl;

    }

}