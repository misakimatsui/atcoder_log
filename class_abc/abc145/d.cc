#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, y;
    std::cin >> x >> y;
    map<int,map<int, int>> mp;
    mp[0][0]++;
    while(true) {
        map<int,map<int, int>> tmp;
        for (int i = 0; i < mp.size(); ++i) {
            for (int j = 0; j < mp[i].size(); ++j) {
                cout << i << " " <<  j << endl;
                if (y < i && x < j) break;
                if (y == i && x == j) {
                    cout << mp[i][j] << endl;
                    return 0;
                }
                tmp[i+1][j+2] += mp[i][j];
                tmp[i+2][j+1] += mp[i][j];
            }
        }
        swap(mp, tmp);
    }
    cout << 0 << endl;
}