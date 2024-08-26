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
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 100001;
const int INF = 1e9;
vector<pii> adj[N];
int n, m, a, b, c, ans = INF;
int d[N][4];
void IJK(int i, int s) {
    priority_queue<pii> p;
    d[s][i] = 0;
    p.push({0, s});
    while (!p.empty()) {
        int u = p.top().se;
        int w = -p.top().fi;
        p.pop();
        if (w > d[u][i]) continue;
        for (auto x : adj[u]) {
            if (d[x.fi][i] > w + x.se) {
                d[x.fi][i] = w + x.se;
                p.push({-d[x.fi][i], x.fi});
            }
        }
    }
}
void solve() {
    for (int i = 1; i <= n; i++)
        d[i][1] = d[i][2] = d[i][3] = INF;
    IJK(1, a); IJK(2, b); IJK(3, c);
    for (int i = 1; i <= n; i++) {
        if (d[i][1] == INF) d[i][1] = 0;
        if (d[i][2] == INF) d[i][2] = 0;
        if (d[i][3] == INF) d[i][3] = 0;
        if (!d[i][1] && !d[i][2] && !d[i][3]) continue;
        ans = min(ans, d[i][1] + d[i][2] + d[i][3]);
    }
    cout << ans;
}
main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    cin >> a >> b >> c;
    solve();
    return 0;
}
