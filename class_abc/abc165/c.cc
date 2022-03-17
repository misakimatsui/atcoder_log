#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int N, M, Q, a[50], b[50], c[50], d[50];
int ans = 0;
int A[10];

void dfs(int cu = 0, int lst = 1) {
	if (cu == N) {
        for (int i = 0; i < N; ++i) {
            cout << A[i] << " ";
        }
        cout << endl;
		return;
	}
    for (int nxt = lst; nxt < M + 1; ++nxt) {
		A[cu] = nxt;
		dfs(cu + 1, nxt);
	}
    cout << "end" << endl;
}
//---------------------------------------------------------------------------------------------------
int main(void) {
	cin >> N >> M >> Q;
    for (int i=0;i< Q;i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--; b[i]--;
	}
	dfs();
	cout << ans << endl;
}