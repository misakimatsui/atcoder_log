#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> vec(10);
    for (auto& x : vec) {
        cin >> x;
    }
    cout << vec[vec[vec[0]]] << endl;
}