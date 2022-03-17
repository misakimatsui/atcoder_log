#include <bits/stdc++.h>

using namespace std;
using ll = long int;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;
    std::vector<double> vec(n);
    for (auto& x : vec) {
        cin >> x;
    }
    for (int i = 0; i < n; ++i) {
        vec[i] = ((vec[i] * (1.0 + vec[i])) / 2.0) / vec[i];
    }
    for (int i = 1; i < n; ++i) {
        vec[i] += vec[i-1];
    }
    vec.insert(vec.begin(), 0);
    double ans = 0.0;
    for (int i = k; i < vec.size(); ++i) {
        ans = std::max(ans, vec[i] - vec[i-k]);
    }
    cout << fixed << setprecision(15) << ans << endl;
}