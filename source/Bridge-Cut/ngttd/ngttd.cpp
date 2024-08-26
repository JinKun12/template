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
vector<int> adj[N];
int id[N], low[N], par[N];
vector<int> res;
void dfs(int u, int p) {
    int child = (par[u] != -1);
    low[u] = id[u] = ++cnt;
    for (int v : adj[u]) if (v != p) {
        if (id[v]) low[u] = min(low[u], id[v]);
        else {
            par[v] = u;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= id[u]) child++;
        }
    }
    if (child >= 2) res.pb(u);
}
main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 0, u , v; i < m; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1; i <= n; i++) if (!par[i])
        par[i] = -1, dfs(i, i);
    cout << sz(res) << '\n';
    sort(all(res));
    for (int x : res)
        cout << x << ' ';
    return 0;
}
