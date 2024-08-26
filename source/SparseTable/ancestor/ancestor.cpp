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
#define int ll
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int maxn = 100001, LG = 16;
int n, m, a[maxn], st[LG + 1][maxn], parent[maxn][LG + 1];
void process() {
    for (int i = 1; i <= n; i++) st[0][i] = a[i];
    for (int j = 1; j <= LG; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
int query(int l, int r) {
    int k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
        cin >> a[i], parent[i][0] = a[i];
    for (int j = 1; j <= LG; j++)
        for (int i = 1; i <= n; i++)
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
    while (m--) {
        int v, k; cin >> v >> k;
        for (int j = LG - 1; j >= 0; j--)
            if ((k >> j) & 1)
                v = parent[v][j];
        cout << v << '\n';
    }
    return 0;
}
