#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

using namespace std;
using ll = long int;
const int inf = INT_MAX;

ll power(ll a,ll n){
	if(n==0)
		return 1;
	else
		return a*power(a,n-1);
}
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    cin >> n;
    for (int i = 0; i <= 37; ++i) {
        for (int j = 0; j <= 25; ++j) {
            if (power(3, i) + power(5, j) == n)  {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    } 
    cout << -1 << endl;
}