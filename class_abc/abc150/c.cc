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
    std::cin >> n;
    std::vector<int> vec(n), p(n), q(n);
    std::iota(vec.begin(), vec.end(), 1);
    for (auto& x : p) {
        cin >> x;
    }
    for (auto& x : q) {
        cin >> x;
    }
    int pval = 0, qval = 0;
    int cnt = 0;
    do {
        cnt++;
        if (vec == p) {
            pval = cnt;
        }
        if (vec == q) {
            qval = cnt;
        }
    } while(next_permutation(vec.begin(), vec.end()));
    cout << abs(qval - pval) << endl;

}