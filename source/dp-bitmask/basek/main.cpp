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
#define bit(i, x) ((x >> i) & 1)
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
const int LG = 16;
int n, k, dp[1 << LG][LG];
main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> k;
    for (int x = 1; x < (1 << n); x++)
    for (int i = 0; i < n; i++) if (bit(i, x)) {
        int p = x - (1 << i);
        if (p == 0) dp[x][i] = 1;
        else {
            for (int j = 0; j < n; j++)
                if (bit(j, x) && abs(j - i) <= k)
                    dp[x][i] += dp[p][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += dp[(1 << n) - 1][i];
    cout << ans;
    return 0;
}
