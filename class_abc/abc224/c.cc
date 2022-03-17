#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<long long, long long>> p(n);
    for (auto &nx : p)
    {
        cin >> nx.first >> nx.second;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                std::cout << i << " " << j << " " << k << std::endl;
                if ((p[j].first - p[i].first) * (p[k].second - p[i].second) - (p[k].first - p[i].first) * (p[j].second - p[i].second) != 0) {
                    res++;
                }
            }
        }
    }
    cout << res << '\n';
}