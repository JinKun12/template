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
const int N = 21;
int n, a[N], b[N];
int mp1[N], mp2[N];
int c[N], dp[1 << N];
main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        mp1[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i]; b[i]--;
        mp2[b[i]] = i;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mp1[i] < mp1[j] && mp2[i] < mp2[j])
                c[j] += (1 << i);
    for (int i = 0; i < n; i++) dp[1 << i] = 1;
    for (int x = 0; x < (1 << n); x++)
        for (int i = 0; i < n; i++)
            if (!bit(i, x) && !(c[i] & x))
                dp[x | (1 << i)] += dp[x];
    cout << dp[(1 << n) - 1];
    return 0;
}
