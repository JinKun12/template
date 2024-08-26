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
const int N = 5e5 + 10;
int n, m, s, p, a[N];
vector<int> adj[N];
vector<pii> Edge;
int cnt, scc, ans;
int low[N], id[N], In[N];
stack<int> st;
int val[N];
void Tarjan(int u) {
    low[u] = id[u] = ++cnt;
    st.push(u);
    for (int v : adj[u]) {
        if (In[v]) continue;
        if (id[v]) low[u] = min(low[u], id[v]);
        else {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == id[u]) {
        scc++;
        while (1) {
            int v = st.top();
            st.pop();
            In[v] = scc;
            val[scc] += a[v];
            if (u == v) break;
        }
    }
}
vector<int> line[N];
int dp[N], mark[N];
int dfs(int u) {
    if (dp[u]) return dp[u];
    dp[u] = mark[u] ? val[u] : -2e18;
    for (int v : line[u])
        dp[u] = max(dp[u], val[u] + dfs(v));
    return dp[u];
}
main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        Edge.pb({u, v});
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        if (!id[i]) Tarjan(i);
    for (auto x : Edge) {
        int u = In[x.fi], v = In[x.se];
        if (u == v) continue;
        line[u].pb(v);
    }
    cin >> s >> p;
    for (int i = 0, x; i < p; i++) {
        cin >> x;
        mark[In[x]] = 1;
    }
    cout << dfs(In[s]);
    return 0;
}
