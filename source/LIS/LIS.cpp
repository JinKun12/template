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
const int N = 1e5 + 10;
int n, a[N], b[N], f[N], ans;
main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        f[i] = lower_bound(b + 1, b + ans + 1, a[i]) - b;
        ans = max(ans, f[i]);
        b[f[i]] = a[i];
    }
    cout << ans << '\n';
    vector<int> T;
    for (int i = n; i >= 1; i--)
        if (f[i] == ans)
            T.pb(a[i]), ans--;
    reverse(all(T));
    for (int x : T)
        cout << x << ' ';
    return 0;
}
