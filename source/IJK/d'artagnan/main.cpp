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
const int N = 105;
const int INF = 2e18;
int n, d[N];
vector<pii> adj[N];
void IJK(int s) {
    d[s] = 0;
    priority_queue<pii> pq;
    pq.push({0, s});
    while (!pq.empty()){
        int u = pq.top().se;
        int l = -pq.top().fi;
        pq.pop();
        if (l > d[u]) continue;
        for (auto [v, w] : adj[u]){
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({-d[v], v});
            }
        }
    }
}
main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    //freopen(Task".inp", "r", stdin);
    cin >> n;
    int u, v, w1, w2; char c;
    while (cin >> u >> v >> w1 >> w2 >> c) {
        if (c == 'M') {
            adj[u].pb({v + n, w1});
            adj[v + n].pb({u, w2});
        } else {
            adj[u + n].pb({v, w1});
            adj[v].pb({u + n, w2});
        }
    }
    fill(d, d + N, INF);
    IJK(n); IJK(2 * n);
    cout << min(d[1], d[n + 1]);
    return 0;
}
