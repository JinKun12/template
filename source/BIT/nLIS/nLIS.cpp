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
const int MOD = 1e9 + 7;
const int N = 100001;
int n, m, a[N];
vector<int> v;
pii T[N];
pii check(pii p, pii q) {
    if (p.fi == q.fi) return {p.fi, (p.se + q.se) % MOD};
    if (p.fi < q.fi) return q;
    return p;
}
void update(int x, pii val) {
    for (; x <= n; x += x & -x) T[x] = check(T[x], val);
}
pii get(int x) {
    pii res = {0, 1};
    for (; x; x -= x & -x) res = check(T[x], res);
    return res;
}
main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], v.pb(a[i]);
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    for (int i = 0; i < n; i++) {
        int x = lower_bound(all(v), a[i]) - v.begin() + 1;
        pii k = get(x - 1);
        update(x, {k.fi + 1, k.se});
    }
    cout << get(n).se;
    return 0;
}
