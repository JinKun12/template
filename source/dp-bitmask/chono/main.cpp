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
const int maxn = 10001;
int n, a[4][maxn], ans = -2e18;
int dp[1 << 16][16];
bool ok[16] = {1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0};
int getVal(int i, int x) {
    int p = 0;
    for (int j = 0; j < 4; j++)
        if (bit(j, x))
            p += a[j][i];
    return p;
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for (int j = 1; j <= n; j++)
        for (int i = 0; i < 4; i++)
            cin >> a[i][j], ans = max(ans, a[i][j]);
    if (ans <= 0) return cout << ans, 0;
    for (int i = 1; i <= n; i++)
        for (int x = 0; x < 16; x++)
            if (ok[x]) {
                int p = getVal(i, x);
                dp[i][x] = -2e18;
                for (int j = 0; j < 16; j++)
                    if (ok[j] && (x & j) == 0)
                        dp[i][x] = max(dp[i][x], dp[i - 1][j] + p);
            }
    for (int x = 0; x < 16; x++)
        if (ok[x]) ans = max(ans, dp[n][x]);
    cout << ans;
    return 0;
}
