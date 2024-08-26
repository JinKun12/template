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
const int maxn = 300001;
struct Data {
    int l, r, w;
};
Data a[maxn];
int n, m, res[maxn], par[maxn];
int get_root(int u) {
    return (u != par[u]) ? par[u] = get_root(par[u]) : par[u];
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n + 1; i++)
        par[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].l >> a[i].r >> a[i].w;
        int l = a[i].l, r = a[i].r, w = a[i].w;
        for (int j = get_root(l); j <= r; j = get_root(j)) {
            if (j != w) {
                res[j] = w;
                par[j] = j + 1;
            }
            else j++;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
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
