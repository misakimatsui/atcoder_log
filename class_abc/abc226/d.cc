#include <iostream>
#include <set>
#include <vector>

using namespace std;

int Gcd(int a, int b) {
    while (b != 0) {
        auto r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int Solve(const vector<pair<int, int>>& points) {
    set<pair<int, int>> spells;
    for (const auto& p1 : points) {
        for (const auto& p2 : points) {
            auto dx = p1.first - p2.first;
            auto dy = p1.second - p2.second;
            if (make_pair(dx, dy) != make_pair(0, 0)) {
                auto gcd = Gcd(abs(dx), abs(dy));
                auto spell = make_pair(dx / gcd, dy / gcd);
                spells.insert(spell);
            }
        }
    }
    return spells.size();
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (auto& p : points) {
        cin >> p.first >> p.second;
    }

    auto res = Solve(points);
    cout << res << "\n";
    return 0;
}
