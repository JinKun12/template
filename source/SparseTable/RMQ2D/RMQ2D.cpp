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
const int N = 510, LG = 10;
int m, n, a[N][N], st[LG + 1][N][LG + 1][N];
void process() {
    for (int k = 0; k <= LG; k++)
    for (int i = 1; i + (1 << k) - 1 <= m; i++)
    for (int l = 0; l <= LG; l++)
    for (int j = 1; j + (1 << l) - 1 <= n; j++) {
        if (k == 0) {
            if (l == 0) st[0][i][0][j] = a[i][j];
            else st[0][i][l][j] = min(st[0][i][l - 1][j], st[0][i][l - 1][j + (1 << (l - 1))]);
        } else st[k][i][l][j] = min(st[k - 1][i][l][j], st[k - 1][i + (1 << (k - 1))][l][j]);
    }
}
int query(int x, int y, int a, int b) {
    int k = __lg(a - x + 1);
    int l = __lg(b - y + 1);
    return min({st[k][x][l][y],
               st[k][a - (1 << k) + 1][l][y],
               st[k][x][l][b - (1 << l) + 1],
               st[k][a - (1 << k) + 1][l][b - (1 << l) + 1]});
}
void solve() {
    int x, y, a, b; cin >> x >> y >> a >> b;
    cout << query(x, y, a, b) << '\n';
}
main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    process();
    ntest;
    return 0;
}
