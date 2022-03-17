#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iomanip>
using namespace std;
using ll = long int;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    std::cin >> q;
    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> que;
    long int tmp = 0;
    for (int i = 0; i < q; ++i) {
        ll query, val;
        std::cin >> query;
        if (query == 1) {
            std::cin >> val;
            que.push(val - tmp);
        }
        else if (query == 2) {
            std::cin >> val;
            tmp += val;
        }
        else { //3
            ll value = que.top() + tmp;
            std::cout << value << std::endl;
            que.pop();
        }

    }
}