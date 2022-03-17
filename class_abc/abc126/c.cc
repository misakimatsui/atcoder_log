#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    int n, k;
    std::cin >> n >> k;
    double ans = 0.0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = i; j < k; j *=2) {
            cnt++;
        }
        ans += 1.0 / n * powf(0.5, cnt);
    }
    cout << fixed << setprecision(15);
    cout << ans << endl;
}