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
const int N = 2e5 + 10;
int n, m;
vector<int> adj[N], ds[N];
int low[N], id[N], In[N], scc, cnt;
stack<int> st;
void dfs(int u) {
    st.push(u);
    low[u] = id[u] = ++cnt;
    for (int v : adj[u]) {
        if (In[v]) continue;
        if (id[v]) low[u] = min(low[u], id[v]);
        else dfs(v), low[u] = min(low[u], low[v]);
    }
    if (id[u] == low[u]) {
        scc++;
        while (1) {
            int x = st.top(); st.pop();
            In[x] = scc;
            ds[scc].pb(x);
            if (x == u) break;
        }
    }
}
void Tarjan() {
    for (int i = 2; i <= n * 2 + 1; i++)
        if (!id[i]) dfs(i);
}
int res[N], used[N];
void Gen(vector<int> v) {
    for (int u : v) if (used[u]) return;
    for (int u : v) {
        if (u & 1) res[u / 2] = -u / 2;
        else res[u / 2] = u / 2;
        used[u] = used[u ^ 1] = 1;
    }
}
main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        u *= 2; v *= 2;
        if (u < 0) u = -u + 1;
        if (v < 0) v = -v + 1;
        adj[u].pb(v^1);
        adj[v].pb(u^1);
    }
    Tarjan();
    for (int i = 1; i <= n; i++)
    if (In[i * 2] == In[i * 2 + 1]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 1; i <= scc; i++) Gen(ds[i]);
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    return 0;
}
