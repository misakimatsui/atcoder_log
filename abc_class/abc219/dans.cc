#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
void chmin(int& x, int y) { x = min(x,y);}

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  const int INF = 1001001001;
  vector dp(x+1, vector<int>(y+1, INF));
  dp[0][0] = 0;
  rep(i,n) {
    int a, b;
    cin >> a >> b;
    for (int j = x; j >= 0; --j) {
      for (int k = y; k >= 0; --k) {
        chmin(dp[min(j+a,x)][min(k+b,y)], dp[j][k]+1);
      }
    }
  }

  int ans = dp[x][y];
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}