#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    string str;
    std::cin >> str;
    vector<int> lvec;
    vector<int> rvec;
    for (int i = 0; i < str.size(); ++i) {
        (str[i] == 'L') ? lvec.push_back(i) : rvec.push_back(-i);
    }
    sort(lvec.begin(), lvec.end());
    sort(rvec.begin(), rvec.end());
    vector<int> ans(str.size(), 0);
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'L') {
            int idx = abs(*(lower_bound(rvec.begin(), rvec.end(), -i)));
            if ((i - idx) % 2 == 0) {
                ans[idx]++;
            }
            else {
                ans[idx+1]++;
            }
        }
        else {
            int idx = *(lower_bound(lvec.begin(), lvec.end(), i));
            if ((idx - i) % 2 == 0) {
                ans[idx]++;
            }
            else {
                ans[idx-1]++;
            }
        }
    }
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}