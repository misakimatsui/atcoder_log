#include <iostream>
#include <vector>
#include <map>
#include <queue>

#include <iterator>
#include <cstdint>
#include <algorithm>

std::map<int, std::vector<int>> mp;
std::vector<int> hoge;
int ans = 0;

long nCr(int n, int r) {
	long ans = 1;
	for (int i = n; i > n-r; --i) {
		ans = ans*i;
	}
	for (int i = 1 ; i < r + 1; ++i) {
		ans = ans / i;
	}
	return ans;
}

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        mp[y].push_back(x);
        hoge.push_back(y);
    }

    std::sort(hoge.begin(), hoge.end());
    hoge.erase(std::unique(hoge.begin(), hoge.end()), hoge.end());

    foreach_comb(hoge.size(), 2, [](int *idx) {
        int cnt = 0; 
        for (int i = 0; i < mp[hoge[idx[0]]].size(); ++i) {
            auto itr = std::find(mp[hoge[idx[1]]].begin(), mp[hoge[idx[1]]].end(), mp[hoge[idx[0]]][i]);
            if (itr != mp[hoge[idx[1]]].end())
            {
                cnt++;
            }
        }
        ans += nCr(cnt, 2);
    });
    std::cout << ans << std::endl;

}