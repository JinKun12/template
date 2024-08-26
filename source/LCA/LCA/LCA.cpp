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
#define int ll
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 100001;
int n, k, m;
int h[N], par[N][20];
vector<int> a[N];
void dfs(int u, int p) {
    h[u] = h[p] + 1;
    par[u][0] = p;
    for (int v : a[u])
        if (v != p)
            dfs(v, u);
}
int lca(int u, int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
        int k = h[u] - h[v];
        for (int j = 0; (1 << j) <= k; j++)
            if (k >> j & 1)
                u = par[u][j];
    }
    if (u == v) return u;
    int k = __lg(h[u]);
    for (int j = k; j >= 0; j--) {
        if (par[u][j] != par[v][j])
            u = par[u][j], v = par[v][j];
    }
    return par[u][0];
}
void solve() {
    cin >> n >> k >> m;
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
    dfs(k, 0);
    for (int j = 1; j < 20; j++)
        for (int i = 1; i <= n; i++)
            par[i][j] = par[par[i][j - 1]][j - 1];
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    int t = 1; while (t--) solve();
    return 0;
}
