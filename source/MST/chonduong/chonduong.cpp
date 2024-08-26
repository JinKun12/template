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
const int maxn = 50001;
struct Data {
    int u, v, w;
};
int n, m, par[maxn], sz[maxn];
vector<Data> a;
void make_set() {
    for (int i = 1; i <= n; i++)
        par[i] = i, sz[i] = 1;
}
bool cmp(Data a, Data b) {
    return a.w < b.w;
}
int Find(int v) {
    return v == par[v] ? v : par[v] = Find(par[v]);
}
bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return true;
}
void kruskal() {
    int ans = 0, cnt = 0;
    while (cnt < sz(a)) {
        if (Union(a[cnt].u, a[cnt].v))
            ans += a[cnt].w, cnt++;
        else a.erase(a.begin() + cnt);
    }
    if (cnt == n - 1) cout << ans << '\n';
    else cout << "-1\n";
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        Data x; cin >> x.u >> x.v >> x.w;
        a.insert(lower_bound(all(a), x, cmp), x);
        make_set();
        kruskal();
    }
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
