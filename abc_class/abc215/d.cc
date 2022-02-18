#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool arr[100100];

//O(sqrt(N))
vector<int> pfact(int x){
  vector<int> res;
  for(int i=2;i*i<=x;i++){
    while(x%i==0){
      x/=i;
      res.push_back(i);
    }
  }
  if(x!=1){res.push_back(x);}
  return res;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;

    std::vector<int> v;

    //O(N) * O(sqrt(N))
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        const auto &vec = pfact(val);
        for (auto x : vec) {
            arr[x] = true;
            v.push_back(x);
        }
    }
    arr[0] = true;
    //O(NlogN)
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    //O(N) * O(NlogN)
    for (int i = 0; i < v.size(); ++i) {
        for (int j = v[i] + v[i]; j <= m; j += v[i]) {
            arr[j] = true;
        }
    }
    int cnt = 0;
    std::vector<int> ans;
    for (int i = 0; i <= m; ++i) {
        if (arr[i] == false) {
            cnt++;
            ans.push_back(i);
        }
    }
    std::cout << cnt << std::endl;
    for (auto x : ans) {
        cout << x << endl;
    }



}