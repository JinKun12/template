/// Created by Zylenox
#include <bits/stdc++.h>
#define Task "task"
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 100001;
int n, m, top = 0, id[N], low[N], scc = 0, cnt = 0;
vector<int> ke[N], res[N];
stack<int> st;
int In[N];
bool cmp(vector<int> &p, vector<int> &q) {
    if (sz(p) != sz(q)) return sz(p) < sz(q);
    return p[0] < q[0];
}
void Tarjan(int &u) {
    low[u] = id[u] = ++cnt;
    st.push(u);
    for (int &v : ke[u]) {
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
            res[scc].pb(v);
            In[v] = scc;
            if (u == v) break;
        }
        sort(all(res[scc]));
    }
}
void solve() {
    for (int i = 1; i <= n; i++)
        if (!id[i]) Tarjan(i);
    cout << scc << '\n';
    sort(res + 1, res + scc + 1, cmp);
    for (int i = 1; i <= scc; i++) {
        cout << sz(res[i]) << '\n';
        for (int u : res[i]) cout << u << ' ';
        cout << '\n';
    }
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
        ke[u].pb(v);
    }
    solve();
    return 0;
}
