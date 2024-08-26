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
const int N = 1e3 + 10;
const int INF = 2e18;
int n, s, t;
vector<pii> G[2][N];
int d[2][N], dp[N * 2][N];
void IJK(vector<pii> adj[], int type) {
    fill(d[type], d[type] + N, INF);
    d[type][t] = 0;
    priority_queue<pii> pq;
    pq.push({0, t});
    while (!pq.empty()) {
        int u = pq.top().se;
        int l = -pq.top().fi;
        pq.pop();
        if (l > d[type][u]) continue;
        for (auto [v, w] : adj[u]) {
            if (d[type][v] > l + w) {
                d[type][v] = l + w;
                pq.push({-d[type][v], v});
            }
        }
    }
}
void read(vector<pii> G[], int type) {
    int m; cin >> m;
    vector<pii> adj[N];
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    IJK(adj, type);
    for (int u = 1; u <= n; u++) {
        for (auto [v, w] : adj[u]) {
            if (d[type][v] < d[type][u])
                G[u].pb({v, w});
        }
    }
}
void Calc(int a[], int b[], int type) {
    for (int u = 1; u <= n; u++)
        if (a[u] != -1)
            for (auto [v, w] : G[type][u])
                b[v] = max(b[v], a[u] + w);
}
main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> s >> t;
    read(G[0], 0);
    read(G[1], 1);
    memset(dp, -1, sizeof dp);
    dp[0][s] = 0;
    for (int k = 0; k < n * 2; k++)
        Calc(dp[k], dp[k + 1], k % 2);
    for (int u = 1; u <= n; u++)
        if (dp[n * 2][u] != -1)
            return cout << -1, 0;
    int res = -1;
    for (int k = 1; k <= n * 2; k++)
        res = max(res, dp[k][t]);
    cout << res;
    return 0;
}
