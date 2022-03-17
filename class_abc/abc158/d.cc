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

    string str;
    std::cin >> str;
    ll q;
    cin >> q;
    ll cnt = 0;
    std::deque<char> deq;
    for (auto& x : str) {
        deq.push_back(x);
    }
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            cnt++;
        }
        else {
            int f;
            char c;
            cin >> f >> c;
            if (f == 1) {
                cnt % 2 == 0 ? deq.push_front(c) : deq.push_back(c);
            }
            else {
                cnt % 2 == 0 ? deq.push_back(c) : deq.push_front(c);
            }
        }
    }
    if (cnt % 2 != 0) {
        auto it = deq.rbegin();
        for (;it != deq.rend(); ++it) {
            cout << *it;
        }
        cout << endl;
    }
    else {
        auto it = deq.begin();
        for (;it != deq.end(); ++it) {
            cout << *it;
        }
        cout << endl;
    }
}