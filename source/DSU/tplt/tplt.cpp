#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1000001;
int parent[maxn];
int find(int u) {
    return parent[u] ? parent[u] = find(parent[u]) : u;
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v)
        parent[u] = v;
}
void solve() {
    int n, m; cin >> n >> m;
    while (m--) {
        int type, u, v; cin >> type >> u >> v;
        if (type == 1) merge(u, v);
        else cout << (find(u) == find(v)) << '\n';
    }
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie();
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    int t = 1; while (t--) solve();
    return 0;
}
