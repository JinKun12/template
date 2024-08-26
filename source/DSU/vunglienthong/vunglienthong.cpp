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
const int N = 1005;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int m, n, q, res[10005], cnt, dem;
int color[N][N];
vector<pii> ds[10005];
struct DSU {
    int root[N * N];
    int get_root(int u) {
        return root[u] ? root[u] = get_root(root[u]) : u;
    }
    void join(int u, int v) {
        if (!u || !v) return;
        int p = get_root(u);
        int q = get_root(v);
        if (p == q) return;
        root[p] = q;
        cnt--;
    }
    void update(int u, int v) {
        color[u][v] = ++dem;
        cnt++;
        for (int i = 0; i < 4; i++) {
            int unew = u + dx[i];
            int vnew = v + dy[i];
            join(dem, color[unew][vnew]);
        }
    }
}; DSU T;
main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> m >> n >> q;
    for (int i = 1, x1, x2, y1, y2; i <= q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int u = x1; u <= x2; u++)
        for (int v = y1; v <= y2; v++)
            if (!color[u][v]) {
                color[u][v] = i;
                ds[i].pb({u, v});
            }
    }
    for (int u = 1; u <= m; u++)
        for (int v = 1; v <= n; v++)
            if (!color[u][v])
                ds[q + 1].pb({u, v});
    memset(color, 0, sizeof color);
    for (int i = q + 1; i > 1; i--) {
        for (auto x : ds[i]) T.update(x.fi, x.se);
        res[i - 1] = cnt;
    }
    for (int i = 1; i <= q; i++)
        cout << res[i] << '\n';
    return 0;
}
