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
struct Edge {
    int u, v, w, id;
};
int n, m, k, par[N];
bool mst[2 * N];
vector<Edge> e;
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}
int getRoot(int u) {
    return (par[u] < 0) ? u : par[u] = getRoot(par[u]);
}
bool Merge(int u, int v) {
    u = getRoot(u); v = getRoot(v);
    if (u == v) return false;
    if (par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return true;
}
void solve() {
    memset(par, -1, sizeof par);
    cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        e.pb({u, v, w, i});
    }
    sort(all(e), cmp);
    int cnt = 0;
    queue<int> q;
    for (int i = 0; i < m; i++) {
        if (Merge(e[i].u, e[i].v) && e[i].w) {
            cnt++;
            mst[i] = true;
            q.push(i);
        }
    }
    if (cnt > k) {
        cout << -1;
        return;
    }
    else {
        memset(par, -1, sizeof par);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            Merge(e[u].u, e[u].v);
        }
        if (cnt < k) {
            for (int i = m - 1; i >= 0; i--) {
                if (!e[i].w) break;
                if (!mst[i] && Merge(e[i].u, e[i].v)) {
                    cnt++;
                    mst[i] = true;
                }
                if (cnt == k) break;
            }
        }
        if (cnt < k) {
            cout << -1;
            return;
        }
        for (int i = 0; i < m; i++) {
            if (e[i].w) break;
            if (!mst[i] && Merge(e[i].u, e[i].v)) {
                cnt++;
                mst[i] = true;
            }
            if (cnt == n - 1) break;
        }
        for (int i = 0; i < m; i++)
            if (mst[i])
                cout << e[i].id << ' ';
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
