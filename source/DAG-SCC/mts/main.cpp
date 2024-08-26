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
int low[N], id[N], lab[N], in[N], out[N];
int n, m, cnt, scc;
bool was[N];
vector<int> a[N];
stack<int> st;
int In[N];
void Tarjan(int &u) {
    low[u] = id[u] = ++cnt;
    st.push(u);
    for (int &v : a[u]) {
        if (was[v]) continue;
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
            lab[v] = scc;
            was[v] = true;
            if (u == v) break;
        }
    }
}
void solve() {
    for (int i = 1; i <= n; i++)
        if (!id[i]) Tarjan(i);
    for (int u = 1; u <= n; u++) {
        for (int v : a[u]) {
            if (lab[u] != lab[v]) {
                in[lab[v]]++;
                out[lab[u]]++;
            }
        }
    }
    int source = 0, sink = 0, s, t;
    for (int i = 1; i <= scc; i++) {
        if (!in[i]) { source++; s = i; }
        if (!out[i]) { sink++; t = i; }
    }
    if (source != 1 || sink != 1) cout << "NO";
    else {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
            if (lab[i] == s) { s = i; break; }
        for (int i = 1; i <= n; i++)
            if (lab[i] == t) { t = i; break; }
        cout << t << ' ' << s;
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
        a[u].pb(v);
    }
    solve();
    return 0;
}
