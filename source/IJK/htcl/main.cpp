/// Created by Zylenox
#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define Task "task"
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define ntest int t; cin >> t; while (t--) solve()
#define yes cout << "yes\n"
#define no cout << "no\n"
#define int ll
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 110;
const int INF = 2e18;
int s, t, n, k, d[N];
vector<pii> adj1[N], adj2[N];
priority_queue<pii> pq;
void Calc(int u, int l, int cur) {
    if (cur == 1) {
        for (auto [v, w] : adj1[u]) {
            if (l % 12 + w <= 12) {
                if (d[v] > l + w) {
                    d[v] = l + w;
                    pq.push({-d[v], v});
                }
            }
        }
    } else {
        for (auto [v, w] : adj2[u]) {
            if (l % 12 + w <= 12) {
                if (d[v] > l + w) {
                    d[v] = l + w;
                    pq.push({-d[v], v});
                }
            }
        }
    }
}
void IJK(int s) {
    fill(d, d + N, INF); d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().se;
        int l = -pq.top().fi;
        pq.pop();
        if (l > d[u]) continue;
        int day = l / 12 + 1;
        int cur = day % 2;
        Calc(u, d[u], cur);
        Calc(u, day * 12, 1 - cur);
        Calc(u, day * 12 + 12, cur);
    }
}
main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> s >> t >> n >> k;
    for (int i = 0, u, v, w; i < k; i++) {
        cin >> u >> v >> w;
        adj1[u].pb({v, w});
        adj2[v].pb({u, w});
    }
    IJK(s);
    cout << d[t];
    return 0;
}
