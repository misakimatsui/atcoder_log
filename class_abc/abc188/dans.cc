#include <bits/stdc++.h>
#include <algorithm>
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
using namespace std;

int main(){
    int N, C_max;
    cin >> N >> C_max;

    vector<ll> A(N), B(N), C(N);
    rep(i, N) cin >> A[i] >> B[i] >> C[i];

    vector<pair<ll, ll>> event;

    // イベントの作成
    rep(i, N){
        // 0-index にする
        event.push_back({A[i] - 1, C[i]});
        event.push_back({B[i], -C[i]});
    }

    // イベントが起こる日を昇順に並べる
    sort(event.begin(), event.end());

    ll ans = 0;
    ll day = 0; // 現在何日目か
    ll charge = 0; // その日に必要な料金

    for (auto &it : event){
        //ll perday = min(C_max, charge);
        ll perday = charge;
        ans += perday * (it.first - day);
        day = it.first;
        charge += it.second;
    }

    cout << ans;
}