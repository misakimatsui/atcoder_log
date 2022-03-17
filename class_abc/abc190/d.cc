#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;


bool is_integer( double x ){
  return std::floor(x)==x;
}

vector<long int> enum_div(long int n){
    vector<long int> ret;
    for(long int i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if(i != 1 && i*i != n){
                ret.push_back(n/i);
            }
        }
    }
    return ret;
}

bool calc(long int val, long int n) {
    double ans = ((static_cast<double>(val) / static_cast<double>(n)) - n + 1) / 2.0;
    return is_integer(ans);
}


int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long int n;
    std::cin >> n;
    n *= 2;
    auto vec = enum_div(n);
    vec.push_back(n);

    int ans = 0;
    for (auto x : vec) {
        if (calc(n, x)) {
            ans++;
        }
    }
    std::cout << ans << std::endl;
}