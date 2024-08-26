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
int n, m, ans = 0;
int h[N], par[N][20], sum[N];
vector<int> a[N];
void dfs(int u) {
    for (int v : a[u])
    if (v != par[u][0]) {
        h[v] = h[u] + 1;
        par[v][0] = u;
        for (int i = 1; i < 20; i++)
            par[v][i] = par[par[v][i - 1]][i - 1];
        dfs(v);
    }
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
void _dfs(int u) {
    for (int v : a[u])
    if (v != par[u][0]) {
        _dfs(v);
        sum[u] += sum[v];
    }
    ans += (sum[u] == 0);
}
void solve() {
    cin >> n;
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
    dfs(1);
    cin >> m;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        int k = lca(u, v);
        sum[u]--; sum[v]--;
        sum[k] += 2;
    }
    _dfs(1);
    cout << ans - 1;
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
