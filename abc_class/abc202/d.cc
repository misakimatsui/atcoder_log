#include <bits/stdc++.h>

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int64_t nCr(int x,int y){
  int64_t r=1;
  if(x<y*2)
    y=x-y;
  for(int i=1;i<=y;i++)  {
    r*=(x-y+i);
    r/=i;
  }
  return r;
}


int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, n; 
    std::cin >> a >> b >> n;
    std::string ans;
    for (int i = a + b - 1;  0 < i; --i) {
        ll tmp = std::pow(2, i);
        if (tmp <= n) {
            ans += 'a';
        }
        else {
            ans += 'b';
        }
        n -= tmp;
    }
    std::cout << ans << std::endl;
}