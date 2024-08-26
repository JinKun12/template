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
const int N = 1e5 + 10;
int n, m, k, l, cnt = 0;
int a[N], b[N];
vector<int> adj[N], e[N];
int id[N], low[N];
vector<pii> res;
void dfs(int u, int p) {
    low[u] = id[u] = ++cnt;
    for (int v : adj[u]) if (v != p) {
        if (id[v]) low[u] = min(low[u], id[v]);
        else {
            dfs(v, u);
            e[u].pb(v);
            e[v].pb(u);
            low[u] = min(low[u], low[v]);
            if (low[v] == id[v])
                res.pb({min(u, v), max(u, v)});
        }
    }
}
int dp1[N], dp2[N], h[N];
void Calc(int u, int p) {
    dp1[u] += a[u];
    dp2[u] += b[u];
    for (int v : e[u]) if (v != p) {
        h[v] = h[u] + 1;
        Calc(v, u);
        dp1[u] += dp1[v];
        dp2[u] += dp2[v];
    }
}
main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m >> k >> l;
    for (int i = 0, x; i < k; i++)
        cin >> x, a[x] = 1;
    for (int i = 0, x; i < l; i++)
        cin >> x, b[x] = 1;
    for (int i = 0, u , v; i < m; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 1);
    Calc(1, 1);
    int ans = 0;
    for (auto [u, v] : res) {
        if (h[u] > h[v]) swap(u, v);
        if (!dp1[v] || !dp2[v] || dp1[v] == k || dp2[v] == l) ans++;
    }
    cout << ans;
    return 0;
}
