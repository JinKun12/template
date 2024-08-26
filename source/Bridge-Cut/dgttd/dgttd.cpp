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
int n, m, cnt = 0;
vector<int> adj[N];
int id[N], low[N];
vector<pii> res;
void dfs(int u, int p) {
    low[u] = id[u] = ++cnt;
    for (int v : adj[u]) if (v != p) {
        if (id[v]) low[u] = min(low[u], id[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == id[v])
                res.pb({min(u, v), max(u, v)});
        }
    }
}
main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        dfs(i, i);
    cout << sz(res) << '\n';
    sort(all(res));
    for (auto [u, v] : res)
        cout << u << ' ' << v << '\n';
    return 0;
}
