#include <bits/stdc++.h>

using namespace std;
using ll = long int;
const int inf = INT_MAX / 2; 

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> vec(n+1, std::vector<int>(n+1, inf));
    for (int i = 0; i < n; ++i) {
        vec[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        --a; --b;
        vec[a][b] = c;
    }
    ll ans = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                vec[i][j] = std::min(vec[i][j], vec[i][k] + vec[k][j]);
                if (vec[i][j] < inf) {
                    ans += vec[i][j];
                }
            }
        }
    }
    std::cout << ans << std::endl;
}