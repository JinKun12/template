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
const int N = 2e5 + 10;
int n, m, cnt = 0;
vector<int> adj[N];
int id[N], low[N], dp[N];
int cc = 0, cnt_bridge = 0;
int cnt_node[N], cnt_connect[N];
void dfs(int u, int p) {
    low[u] = id[u] = ++cnt;
    cnt_node[cc]++;
    for (int v : adj[u]) if (v != p) {
        if (id[v]) low[u] = min(low[u], id[v]);
        else {
            dfs(v, u);
            dp[u] += dp[v];
            low[u] = min(low[u], low[v]);
            if (low[v] == id[v]) {
                cnt_bridge++;
                cnt_connect[cc] += dp[v] * (n - dp[v]) - 1;
            }
        }
    }
    dp[u]++;
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
    for (int i = 1; i <= n; i++) if (!id[i]) {
        cc++;
        if (cc == 3) return cout << 0, 0;
        dfs(i, i);
    }
    if (cc == 1) cout << cnt_connect[1] + (m - cnt_bridge) * (n * (n - 1) / 2 - m);
    else cout << (m - cnt_bridge) * cnt_node[1] * cnt_node[2];
    return 0;
}
