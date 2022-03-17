#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

long int nCr(int x,int y) {
  long int r = 1;
  if (x < y * 2) {
    y = x - y;
  }
  for(int i = 1; i<=y; ++i) {
    r *= (x - y + i);
    r /= i;
  }
  return r;
}
 
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    n -= 12;
    std::cout << nCr(n + 11, 11) << std::endl;
}