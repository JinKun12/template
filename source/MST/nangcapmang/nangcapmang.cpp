/// Created by Zylenox
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
struct Edge {
    int u, v, w;
}; Edge e[N];
bool cmp(Edge p, Edge q) {
    return p.w > q.w;
}
int n, m, root[N], h[N], ans;
vector<pii> a[N];
pii par[N][20];
bool mst[N];
int getRoot(int u) {
    return (root[u] == 0) ? u : root[u] = getRoot(root[u]);
}
void MST() {
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        int p = getRoot(e[i].u);
        int q = getRoot(e[i].v);
        if (p == q) continue;
        root[p] = q;
        mst[i] = true;
        a[e[i].u].pb({e[i].v, e[i].w});
        a[e[i].v].pb({e[i].u, e[i].w});
    }
}
void dfs(int u, int p) {
    for (auto x : a[u]) {
        int v = x.fi;
        if (v == p) continue;
        h[v] = h[u] + 1;
        par[v][0] = {u, x.se};
        for (int j = 1; j <= 18; j++) {
            par[v][j].fi = par[par[v][j - 1].fi][j - 1].fi;
            par[v][j].se = min(par[par[v][j - 1].fi][j - 1].se, par[v][j - 1].se);
        }
        dfs(v, u);
    }
}
pii lca(int u, int v) {
    pii p; p.se = 2e18;
    if (h[u] > h[v]) swap(u, v);
    int k = h[v] - h[u];
    for (int i = 18; i >= 0; i--)
    if ((k >> i) & 1) {
        p.se = min(p.se, par[v][i].se);
        v = par[v][i].fi;
    }
    if (u == v) return {u, p.se};
    for (int i = 18; i >= 0; i--)
    if (par[u][i].fi != par[v][i].fi) {
        p.se = min({p.se, par[u][i].se, par[v][i].se});
        u = par[u][i].fi; v = par[v][i].fi;
    }
    return {par[u][0].fi, min({p.se, par[u][0].se, par[v][0].se})};
}
void solve() {
    MST();
    h[1] = 1;
    dfs(1, 0);
    for (int i = 1; i <= m; i++)
    if (!mst[i]) {
        pii l = lca(e[i].u, e[i].v);
        ans += max(0ll, l.se - e[i].w);
    }
    cout << ans;
}
main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    solve();
    return 0;
}
