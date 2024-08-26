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
const int maxn = 5001;
vector<pii> a;
int n, m, d[maxn];
bool visited[maxn];
bool mark[maxn][maxn];
int pro(int i, int j) {
    return ((a[i].fi - a[j].fi) * (a[i].fi - a[j].fi)) + ((a[i].se - a[j].se) * (a[i].se - a[j].se));
}
void solve() {
    cin >> n; a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        d[i] = 2e18;
    }
    cin >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        mark[a][b] = mark[b][a] = 1;
    }
    db ans = 0;
    int idx = 1;
    visited[1] = 1;
    while (true) {
        int found = 2e18, tmp = 2e18;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && i != idx) {
                if (mark[idx][i]) d[i] = 0;
                else d[i] = min(d[i], pro(i, idx));
                if (tmp > d[i]) tmp = d[i], found = i;
            }
        }
        if (found == 2e18) {
            cout << fixed << setprecision(2) << ans;
            return;
        }
        else {
            ans += sqrt(tmp);
            idx = found;
            visited[found] = 1;
        }
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
