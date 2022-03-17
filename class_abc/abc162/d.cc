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
    cin >> str;
    vector<int> rvec;
    vector<int> gvec;
    vector<int> bvec;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'R') {
            rvec.push_back(i);
        }
        else if (str[i] == 'G') {
            gvec.push_back(i);
        }
        else {
            bvec.push_back(i);
        }
    }
    for (int r = 0; r < rvec.size(); ++r) {
        auto it = upper_bound(gvec.begin(), gvec.end(), rvec[r]);
        int g = distance(gvec.begin(), it);
        for (; g < gvec.size(); ++g) {
            auto it2 = upper_bound(bvec.begin(), bvec.end(), gvec[g]);
            int b = distance(bvec.begin(), it2);
            for (; b < bvec.size(); ++b) {
                if ()

            }
        }
    }
}