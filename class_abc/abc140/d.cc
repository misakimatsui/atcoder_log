#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  string str;
  cin >> n >> k >> str;
  int a = 0;
  for (int i = 0; i + 1 < n; ++i) {
      if (str[i] != str[i+1]) {
          ++a;
      }
  }
  cout << n - 1 - max(a - k*2, 0) << endl;
}