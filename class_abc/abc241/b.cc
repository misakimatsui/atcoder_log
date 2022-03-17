#include <bits/stdc++.h>
#include <atcoder/all>


//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace atcoder;
using namespace std;

//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace atcoder;
using namespace std;

using mint = modint998244353;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    string str;
    std::cin >> str;
    std::vector<char> vec;
    for (int i = 0; i < str.size(); ++i) {
        vec.push_back(str[i]);
    }
    sort(vec.begin(), vec.end());
    for (auto x : vec) {
        cout << x;
    }
    cout << endl;
}