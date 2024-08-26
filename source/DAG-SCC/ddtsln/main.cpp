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
vector<pii> e[N];
int n, m, dp[N];
int dfs(int u) {
    if (dp[u] != -1) return dp[u];
    dp[u] = 0;
    for (auto [v, w] : e[u])
        dp[u] = max(dp[u], w + dfs(v));
    return dp[u];
}
void solve() {
    memset(dp, -1, sizeof dp);
    for (int u = 1; u <= n; u++)
        if (dp[u] == -1)
            dp[u] = dfs(u);
    cout << *max_element(dp + 1, dp + n + 1);
}
main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        e[u].pb({v, w});
    }
    solve();
    return 0;
}
