#include <bits/stdc++.h>
#define Task "task"
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 100001;
int n, q, h[N], par[N][20], d[N];
vector<pii> a[N];
void dfs(int u, int p) {
    h[u] = h[p] + 1;
    par[u][0] = p;
    for (auto x : a[u])
        if (x.fi != p) {
            d[x.fi] = d[u] + x.se;
            dfs(x.fi, u);
        }
}
int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int k = h[u] - h[v];
    for (int j = 0; (1 << j) <= k; j++)
        if (k & (1 << j))
            u = par[u][j];
    if (u == v) return u;
    for (int j = 19; j >= 0; j--)
        if (par[u][j] != par[v][j])
            u = par[u][j], v = par[v][j];
    return par[u][0];
}
void solve(int n) {
    for (int i = 1; i <= n; i++) a[i].clear();
    memset(h, 0, sizeof h);
    for (int u = 1, v, w; u < n; u++) {
        cin >> v >> w;
        a[u + 1].pb({v + 1, w});
        a[v + 1].pb({u + 1, w});
    }
    dfs(1, 0);
    for (int j = 1; j < 20; j++)
        for (int i = 1; i <= n; i++)
            par[i][j] = par[par[i][j - 1]][j - 1];
    cin >> q;
    while (q--) {
        int u, v; cin >> u >> v; u++; v++;
        int k = lca(u, v);
        cout << d[u] + d[v] - 2 * d[k] << ' ';
    }
    cout << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    int t; while (cin >> t && t) solve(t);
    return 0;
}
