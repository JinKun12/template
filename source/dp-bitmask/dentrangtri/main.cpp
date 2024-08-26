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
int n, m, c[maxn][maxn];
int dp[1 << maxn][maxn];
string a[maxn];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    a[m] = string(n, '0');
    for (int i = 0; i < m; i++)
    for (int j = i + 1; j <= m; j++)
    for (int k = 0; k < n; k++)
        if (a[i][k] != a[j][k])
            c[i][j]++, c[j][i]++;
    for (int x = 0; x < (1 << m); x++)
    for (int i = 0; i < m; i++)
        if (bit(i, x)) {
            int p = x - (1 << i);
            if (p == 0) dp[x][i] = c[i][m];
            else {
                dp[x][i] = 2e18;
                for (int j = 0; j < m; j++)
                    if (bit(j, p))
                        dp[x][i] = min(dp[x][i], dp[p][j] + c[j][i]);
            }
        }
    int ans = 2e18;
    for (int i = 0; i < m; i++)
        ans = min(ans, dp[(1 << m) - 1][i]);
    cout << ans;
    return 0;
}
