#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    string str;
    std::cin >> n;
    vector<pair<pair<ll, ll>, char>> vec(n);
    for (auto& x : vec) {
        cin >> x.first.first >> x.first.second; // x, y
    }
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        vec[i].second = str[i];
    }
    std::sort(vec.begin(), vec.end(), 
    [](auto& a, auto& b) {
        if (a.first.second == b.first.second) {
            return a.first.first < b.first.first;
       }
           return a.first.second < b.first.second;
       });

    map<ll, string> mp;
    for (int i = 0; i < vec.size(); ++i) {
        mp[vec[i].first.second]+=(vec[i].second);
    }
    for (const auto& [y, v] : mp) {
        int ll =v.find('R');
        int rr =v.rfind('L');
        if (ll != -1 && rr != -1 && ll < rr) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}