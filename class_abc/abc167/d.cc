#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, k;
    std::cin >> n >> k;
    std::vector<ll> vec(n);
    std::vector<bool> p(n, false);
    std::vector<bool> p2(n, false);
    for (auto& x : vec) {
        cin >> x;
        --x;
    }
    ll idx = 0;
    ll cnt = 0;
    ll cnt2 = 0;
    bool loop = false;
    bool loop2 = false;
    while (cnt < k) {
        cnt++;
        p[idx] = true;
        idx = vec[idx];
        if (p[idx] == true) {
            loop = true;
            break;
        }
    }
    if (!loop) {
        cout << idx + 1 << endl;
    }
 
   else {
        while (cnt2 < k) {
            cnt2++;
            p2[idx] = true;
            idx = vec[idx];
            if (p2[idx] == true) {
                loop2 = true;
                break;
            }
        }
        ll a = (k - cnt) % cnt2;
        while(0 < a) {
            --a;
            idx = vec[idx];
        }
        cout << idx + 1 << endl;
    }
}