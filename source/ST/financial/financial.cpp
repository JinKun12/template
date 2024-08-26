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
const int N = 1e6 + 10;
int n, k, a[N];
int T[N], id[N], dp[N], ans[N];
void init(int node, int l, int r) {
    if (l == r) {
        T[node] = dp[l];
        id[l] = node;
        return;
    }
    int mid = l + (r - l) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    T[node] = max(T[node * 2], T[node * 2 + 1]);
}
int get(int node, int l, int r, int u, int v) {
    if (u > r || v < l) return -2e18;
    if (u <= l && r <= v) return T[node];
    int mid = l + (r - l) / 2;
    int low = get(node * 2, l, mid, u, v);
    int high = get(node * 2 + 1, mid + 1, r, u, v);
    return max(low, high);
}
void update(int pos, int val) {
    int node = id[pos];
    T[node] = dp[pos] = val;
    while (node > 1) {
        node /= 2;
        T[node] = max(T[node * 2], T[node * 2 + 1]);
    }
}
main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> k; vector<int> v;
    for (int i = 1; i <= n; i++)
        cin >> a[i], v.pb(a[i]);
    sort(all(v));
    init(1, 1, n);
    for (int i = 1; i <= n; i++) {
        int p = upper_bound(all(v), a[i] - k) - v.begin();
        int q = lower_bound(all(v), a[i] + k) - v.begin() + 1;
        int pos = lower_bound(all(v), a[i]) - v.begin() + 1;
        ans[i] = max(get(1, 1, n, 1, p), get(1, 1, n, q, n)) + 1;
        dp[pos] = max(dp[pos], ans[i]);
        update(pos, dp[pos]);
    }
    cout << *max_element(ans + 1, ans + n + 1);
    return 0;
}
