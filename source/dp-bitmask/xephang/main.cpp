/// Created by Zylenox
#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define Task "task"
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define bit(i, x)((x >> i) & 1)
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int maxn = 22;
int n, a[maxn][maxn];
ll dp[1 << maxn];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    dp[0] = 0;
    for (int x = 0; x < (1 << n); x++) {
        int k = __builtin_popcount(x);
        for (int i = 0; i < n; i++)
        if (bit(i, x) == 0) {
            int u = x + (1 << i);
            dp[u] = max(dp[u], dp[x] + a[i][k + 1]);
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
    return 0;
}
