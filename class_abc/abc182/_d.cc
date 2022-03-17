#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), S(N+1, 0), M(N+1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        S[i+1] = S[i] + A[i];
        M[i+1] = max(M[i], S[i+1]);
    }
    long long res = 0, cur = 0;
    for (int i = 0; i < N; ++i) {
        res = max(res, cur + M[i+1]);
        cur += S[i+1];
    }
    cout << res << endl;
}