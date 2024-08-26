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
#define bit(i, x) ((x >> i) & 1)
#define int ll
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int maxn = 16;
int n, a[maxn];
pii dp[1 << maxn][maxn];
int par(int x, int y) {
    return 2*(x + 1) - 2*min(x, y);
}
void solve() {
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int x = 1; x < (1 << n); x++)
    for (int i = 0; i < n; i++)
        if (bit(i, x)) {
            int p = x - (1 << i);
            if (p == 0) dp[x][i] = {(a[i] + 1) * 2, 1};
            else {
                for (int j = 0; j < n; j++) {
                    int cur = dp[p][j].fi + par(a[i], a[j]);
                    if (bit(j, x) && i != j) {
                        if (dp[x][i].fi < cur)
                            dp[x][i] = {cur, dp[p][j].se};
                        else if (dp[x][i].fi == cur)
                            dp[x][i].se += dp[p][j].se;
                    }
                }
            }
        }
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++)
        ans1 = max(ans1, dp[(1 << n) - 1][i].fi);
    for (int i = 0; i < n; i++)
        if (dp[(1 << n) - 1][i].fi == ans1)
            ans2 += dp[(1 << n) - 1][i].se;
    cout << ans1 << ' ' << ans2 << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    while (cin >> n && n) solve();
    return 0;
}
