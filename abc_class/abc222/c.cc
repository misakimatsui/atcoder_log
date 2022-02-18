#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>

int judge(char f, char s){
    if (f == s) {
        return 0;
    }
    if (f == 'G' && s == 'C') { return 1; }
    if (f == 'P' && s == 'G') { return 1; }
    if (f == 'C' && s == 'P') { return 1; }
    return -1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> mp; //rank, N
    std::vector<std::vector<char>> vec(2 * n, std::vector<char>(m));
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < m; ++j) {
            char n;
            std::cin >> n;
            vec[i][j] = n;
        }
        mp.push_back(std::make_pair(0, i));
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 2 * n; j+=2) {
            char f = vec[mp[j].second][i];
            char s = vec[mp[j+1].second][i];
            int result = judge(f, s);

            if (result == 1) {
                mp[j].first++;
            }
            else if(result == -1){
                mp[j+1].first++;
            }
        }
        std::sort(mp.begin(), mp.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
             if (a.first == b.first) {
                 return a.second < b.second;
            }
         return a.first > b.first;
        }

        );
    }
    for (auto X : mp) {
        std::cout << X.first << " " << X.second << std::endl;
    }


}