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
int n, m, s, t, pre[N], d[N];
vector<int> adj[N];
int get(int u, int v){
    int a = u, b = v;
    vector<int> x, y;
    x.pb(a); y.pb(b);
    while(a != b){
        a = pre[a]; x.pb(a);
        b = pre[b]; y.pb(b);
    }
    x.pb(a); y.pb(b);
    sort(all(x)); sort(all(y));
    for (int i = 0; i < sz(x); i++)
        if (x[i] != y[i])
            return (x[i] < y[i]) ? u : v;
    return u;
}
bool visited[N];
void bfs() {
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                d[v] = d[u] + 1;
                pre[v] = u;
                visited[v] = true;
                q.push(v);
            }
            else if (d[v] == d[u] + 1 && pre[v] != u)
                pre[v] = get(u, pre[v]);
        }
    }
}
void solve() {
    bfs();
    if (!pre[t]) { cout << -1; return; }
    vector<int> res;
    while (t != s) {
        res.pb(t);
        t = pre[t];
    } res.pb(s);
    reverse(all(res));
    for (int x : res)
        cout << x << ' ';
}
main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m >> s >> t;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    solve();
    return 0;
}
