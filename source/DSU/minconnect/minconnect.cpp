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
const int maxn = 100001;
int n, m, visited[maxn], sz[maxn], res[maxn], root[maxn];
pii p[maxn];
vector<int> adj[maxn];
bool cmp(pii a, pii b) {
    return a.se >= b.se;
}
int get_root(int u) {
    return root[u] ? (root[u] = get_root(root[u])) : u;
}
void join(int u, int v) {
    u = get_root(u);
    v = get_root(v);
    if (u == v) return;
    root[u] = v;
    sz[v] += sz[u];
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].se; p[i].fi = i;
        sz[i] = 1; res[i] = -1;
    }
    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        int u = p[i].fi;
        visited[u] = 1;
        for (int v : adj[u])
            if (visited[v] == 1) join(u, v);
        int Size = sz[get_root(u)];
        if (res[Size] == -1)
            res[Size] = p[i].se;
    }
    for (int i = n - 1; i >= 1; i--)
        res[i] = max(res[i], res[i + 1]);
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
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
