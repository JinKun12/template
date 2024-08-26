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
const int maxn = 100001;
int n, m, par[2 * maxn];
pii a[maxn];
int get_root(int u) {
    return par[u] == u ? u : par[u] = get_root(par[u]);
}
bool process(int cur, int r) {
    bool flag = true;
    int tmp = get_root(r + 1);
    while (cur <= r) {
        int u = get_root(cur);
        if (u != cur) flag = false;
        par[cur] = tmp;
        cur = u + 1;
    }
    return flag;
}
void solve() {
    cin >> n >> m;
    vector<int> v;
    for (int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r;
        v.pb(l); v.pb(r);
        a[i] = {l, r};
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    for (int i = 1; i <= sz(v) + 1; i++)
        par[i] = i;
    int ans = 0;
    for (int i = m; i >= 1; i--) {
        a[i].fi = lower_bound(all(v), a[i].fi) - v.begin() + 1;
        a[i].se = lower_bound(all(v), a[i].se) - v.begin() + 1;
        ans += process(a[i].fi, a[i].se);
    }
    cout << ans;
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    int t = 1; while (t--) solve();
    return 0;
}
