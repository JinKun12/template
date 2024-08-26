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
int n, m, s, p;
vector<int> adj[N];
int cnt, scc, ans;
int low[N], id[N], In[N];
stack<int> st;
set<pii> a;
void Tarjan(int &u) {
    low[u] = id[u] = ++cnt;
    st.push(u);
    for (int &v : adj[u]) {
        if (In[v]) continue;
        if (id[v]) low[u] = min(low[u], id[v]);
        else {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == id[u]) {
        scc++;
        int tmp = 0;
        while (1) {
            int v = st.top();
            st.pop();
            tmp++;
            In[v] = scc;
            if (u == v) break;
        }
        ans += 1ll * tmp * (tmp - 1);
    }
}
void solve() {
    for (int i = 1; i <= n; i++)
        if (!id[i]) Tarjan(i);
    for (auto &x : a)
        if (In[x.fi] == In[x.se])
            ans--;
    cout << ans;
}
main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        a.insert({u, v});
    }
    solve();
    return 0;
}
