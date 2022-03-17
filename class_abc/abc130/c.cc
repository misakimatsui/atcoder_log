#include <bits/stdc++.h>

using namespace std;
using ll = long int;
const int inf = INT_MAX;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double w, h, x, y;
    std::cin >> w >> h >> x >> y;
    cout << fixed << setprecision(15);
    cout << w * h / 2  << " ";
    if (w / 2 == x && h / 2 == y) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
}