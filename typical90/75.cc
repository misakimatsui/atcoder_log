#include <iostream>
#include <vector>
using namespace std;
long int cnt = 0;

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        while (N % a == 0) {
            cnt++;
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }

    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    long long N;
    cin >> N;
    const auto &res = prime_factorize(N);
    std::cout << cnt << std::endl;
}