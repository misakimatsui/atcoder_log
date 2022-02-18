#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int main() {
  ll L, R;
  cin >> L >> R;
  
  mint cnt = 0;
  ll p = 1;
  for (int i = 0; i <= 18; i++) {
    ll l = max(L, p), r = min(R + 1, p * 10);
    if (i == 18) r = R + 1;
    if (l >= r) {
      p *= 10;
      continue;
    }
    cnt += mint(i + 1) * (r - l) * (r + l - 1) / 2;
    p *= 10;
  }
  
  cout << cnt.val() << endl;
}