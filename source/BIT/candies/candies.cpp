#include <bits/stdc++.h>
#define Task "task"
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 100001;
int m, n, a[N], T[N];
int sum(int x) {
    int res = 0;
    for (; x <= n; x += x & -x) res += T[x];
    return res;
}
void add(int x, int val) {
    for (; x > 0; x -= x & -x) T[x] += val;
}
int Find_last(int t) {
    int x = 0, sum = 0;
    for (int i = log2(n); i >= 0; i--) {
        int u = x + (1 << i);
        if (a[u] - sum - T[u] >= t) x = u;
        else sum += T[u];
    }
    return x;
}
void solve() {
    int t; cin >> t;
    int pos = Find_last(t);
    cout << pos << '\n';
    add(pos, 1);
}
main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    cin >> m; while (m--) solve();
    return 0;
}
