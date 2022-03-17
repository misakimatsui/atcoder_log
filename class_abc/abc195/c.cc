#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long int n;
    std::cin >> n;
    long int cnt = 0;
    long int i = 1000;
    long int val = 0;
    for (; i < n; i *=1000) {
        val = 1000 * i - 1;
        if (n <= val) {
            break;
        }
        cnt += ((val) - i + 1) * (log(i) /log(1000));
    }
    if(i <= n) {
        cnt += (n - i + 1) * (log(i) / log(1000));
    }
    std::cout << cnt << std::endl;
}