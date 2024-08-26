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
const int N = 2e5 + 10, LG = 20;
int n, m, a[N], st[LG + 1][N];
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
main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    process();
    while (m--) {
        int t, l, r; cin >> t >> l >> r;
        while (query(l, r) <= t){
            int hi = r;
            while (hi - l > 1){
                int mid = (l + hi) >> 1;
                if (query(l, mid) <= t) hi = mid;
                else l = mid;
            }
            if (a[l] <= t) t %= a[l];
            if (a[hi] <= t) t %= a[hi];
        }
        cout << t << '\n';
    }
    return 0;
}
