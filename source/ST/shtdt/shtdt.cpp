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
const int MOD = 1000000007;
int n, m, a[maxn], id[maxn];
pii st[4 * maxn];
void build(int node, int l, int r) {
    st[node] = {0, 1};
    if (l == r){
        id[l] = node;
        return;
    }
    int mid = l + (r - l) / 2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
}
int get(int x)  {
    int pos = id[x], ans = a[x];
    while (pos > 0) {
        ans = (ans * st[pos].se + st[pos].fi) % MOD;
        pos /= 2;
    }
    return ans;
}
void add(pii &a, pii b) {
    a.fi = (a.fi * b.se + b.fi) % MOD;
    a.se = (a.se * b.se) % MOD;
}
void update(int node, int l, int r, int u, int v, int sum, int val) {
    if (u > r || v < l) return;
    if (l >= u && r <= v) {
        if (val == 1) st[node].fi = (st[node].fi + sum) % MOD;
        if (sum == 0) {
            st[node].fi = (st[node].fi * val) % MOD;
            st[node].se = (st[node].se * val) % MOD;
        }
        return;
    }
    add(st[node*2], st[node]);
    add(st[node*2+1], st[node]);
    st[node] = {0, 1};
    int mid = l + (r - l) / 2;
    update(node*2, l, mid, u, v, sum, val);
    update(node*2+1, mid+1, r, u, v, sum, val);
}
void solve() {
    char type; int u, v, d;
    cin >> type >> u;
    if (type == '?') {
        cout << get(u) << '\n';
        return;
    }
    cin >> v >> d;
    if (type == '+') update(1, 1, n, u, v, d, 1);
    else update(1, 1, n, u, v, 0, d);
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cin >> m; while (m--) solve();
    return 0;
}
