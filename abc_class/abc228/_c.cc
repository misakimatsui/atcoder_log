#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    k -= 1;
    vector<int> p(n);
    for (int& x : p) {
        int a, b, c;
        cin >> a >> b >> c;
        x = a + b + c;
    }
    vector<int> q = p;

    for (auto x : p) {
        std::cout << x << ",";
    }
    std::cout << std::endl;
    for (auto x : q) {
        std::cout << x << ",";
    }
    std::cout << std::endl;
    std::cout <<  "------------" << std::endl;


    sort(begin(q), end(q), greater<>());

    for (auto x : p) {
        std::cout << x << ",";
    }
    std::cout << std::endl;
    for (auto x : q) {
        std::cout << x << ",";
    }
    std::cout << std::endl;


    for (int x : p) {
        cout << (x + 300 >= q[k] ? "Yes" : "No") << '\n';
    }
}
