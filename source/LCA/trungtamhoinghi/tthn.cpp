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
#define ntest int t; cin >> t; while (t--) solve()
#define yes cout << "yes\n"
#define no cout << "no\n"
#define int ll
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 2e5 + 10;
const int INF = 2e18;
struct Data {
    int l, r, i;
} a[N];
int n;
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].i = i;
    }
    sort(a + 1, a + n + 1, [](const Data &a, const Data &b) {
        return a.r < b.r;
    });
}
int dp[N], lst[N], par[N];
void solve() {
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i - 1, w = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid].r < a[i].l) w = mid, l = mid + 1;
            else r = mid - 1;
        }
        int cur = dp[w] + 1;
        par[i] = lst[w];
        if (dp[i - 1] > cur) {
            dp[i] = dp[i - 1];
            lst[i] = lst[i - 1];
        }
        else if (dp[i - 1] == cur) {
            dp[i] = cur;
            int u = lst[i - 1], v = i;
            int mn1 = INF, mn2 = INF;
            while (par[u] != par[v]){
                if (a[u].i < mn1) mn1 = a[u].i;
                if (a[v].i < mn2) mn2 = a[v].i;
                u = par[u]; v = par[v];
            }
            if (a[u].i < mn1) mn1 = a[u].i;
            if (a[v].i < mn2) mn2 = a[v].i;
            if (mn1 < mn2) lst[i] = lst[i - 1];
            else dp[i] = cur, lst[i] = i;
        }
        else dp[i] = cur, lst[i] = i;
    }
}
void output() {
    cout << dp[n] << '\n';
    int cur = lst[n];
    vector<int> res;
    while (cur) res.pb(a[cur].i), cur = par[cur];
    sort(all(res));
    for (int x : res) cout << x << ' ';
}
main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    input();
    solve();
    output();
    return 0;
}
