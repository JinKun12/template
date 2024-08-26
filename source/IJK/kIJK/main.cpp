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
typedef vector<int> vi;
const int N = 1e3 + 10;
const int INF = 2e18;
int n, m, k, d[N][N];
vector<pii> adj[N];
void IJK(int s) {
    priority_queue<pii> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().se;
        int l = -pq.top().fi;
        pq.pop();
        if (l > d[u][k]) continue;
        for (auto [v, w] : adj[u]) {
            int val = l + w;
            int idx = lower_bound(d[v] + 1, d[v] + k, val) - d[v];
            if (val >= d[v][idx]) continue;
            else {
                for (int i = k; i >= idx + 1; i--)
                    d[v][i] = d[v][i - 1];
                d[v][idx] = val;
                pq.push({-val, v});
            }
        }
    }
}
main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    //freopen(Task".inp", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    fill(*d, *d + N * N, INF);
    d[1][1] = 0;
    IJK(1);
    if (d[n][1] == INF) return cout << "-1\n", 0;
    for (int i = 1; i <= k; i++)
        cout << d[n][i] << ' ';
    return 0;
}
