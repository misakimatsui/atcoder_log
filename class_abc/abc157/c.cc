#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;
//20分
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, char>> vec(m); //s, c
    for (int i = 0; i < m; ++i) {
        int s, c;
        cin >> s >> c;
        --s;
        vec[i].first = s;
        vec[i].second = '0' + c;
    }
    for (int ans = 0; ans < 1000; ++ans) {
        string str = std::to_string(ans);
        if(str.size() != n) continue;
        bool isok = true;
        for (int i = 0; i < vec.size(); ++i) {
            if (str[vec[i].first] != vec[i].second) {
                isok = false;
            }
        }
        if (isok) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
}