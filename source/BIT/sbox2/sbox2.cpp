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
int n, m, T[N];
void add(int x, int val) {
    for (; x <= n; x += x & -x) T[x] += val;
}
int sum(int x) {
    int res = 0;
    for (; x; x -= x & -x) res += T[x];
    return res;
}
main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    while (m--) {
        int t, l, r, d; cin >> t >> l;
        if (t == 1) {
            cin >> r >> d;
            add(l, d); add(r + 1, -d);
        } else cout << sum(l) << '\n';
    }
    return 0;
}
