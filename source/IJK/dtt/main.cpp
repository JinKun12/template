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
const int N = 150 + 10;
const int INF = 1e9;
struct Edge {
    int v, c, d;
}; vector<Edge> adj[N];
int n, m, s, t, w;
db dist[N], ans = INF;
void IJK(int Cmin) {
    fill(dist, dist + N, INF);
    priority_queue<pii> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().se;
        int w = -pq.top().fi;
        pq.pop();
        if (w > dist[u]) continue;
        for (auto x : adj[u]) {
            if (Cmin > x.c) continue;
            if (dist[x.v] > w + x.d) {
                dist[x.v] = w + x.d;
                pq.push({-dist[x.v], x.v});
            }
        }
    }
}
vector<int> vec;
void solve() {
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
    for (int x : vec) {
        IJK(x);
        if (dist[t] == INF) continue;
        ans = min(ans, dist[t] + (db)w / (db)x);
    }
    cout << fixed << setprecision(2) << ans;
}
main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m >> s >> t >> w;
    for (int i = 1, u, v, c, d; i <= m; i++) {
        cin >> u >> v >> c >> d;
        adj[u].pb({v, c, d});
        adj[v].pb({u, c, d});
        vec.pb(c);
    }
    solve();
    return 0;
}
