#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
vector<int> pfact(int x){
  vector<int> res;
  for(int i=2;i*i<=x;i++){
    cnt++;
    while(x%i==0){
      x/=i;
      res.push_back(i);
    }
  }
  if(x!=1){res.push_back(x);}
  return res;
}

int main() {
    long long N;
    cin >> N;
    const auto &res2 = pfact(N);
    for (auto x : res2) {
        std::cout << x;
    }

    std:cout << "---------" << std::endl;
    std::cout << cnt << std::endl;
}