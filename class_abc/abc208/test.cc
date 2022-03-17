#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


int N, M;
int dist[401][401];
void _main() {
	cin >> N >> M;

	rep(i, 0, N) rep(j, 0, N) dist[i][j] = inf;
	rep(i, 0, N) dist[i][i] = 0;

	rep(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		dist[a][b] = c;
	}

	ll ans = 0;
	rep(k, 0, N) {
		rep(i, 0, N) rep(j, 0, N) chmin(dist[i][j], dist[i][k] + dist[k][j]);
		rep(i, 0, N) rep(j, 0, N) if (dist[i][j] < inf) ans += dist[i][j];
	}
	cout << ans << endl;
}