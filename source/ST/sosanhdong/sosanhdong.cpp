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
const int MOD = 1e9 + 7;
const int base = 2;
string s; int n, t;
int T[N], h[N], a[N], Size[N], id[N];
void init(int node, int l, int r) {
    if (l == r) {
        T[node] = a[l];
        Size[node] = 1;
        id[l] = node;
        return;
    }
    int mid = l + (r - l) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    T[node] = (T[node * 2] * h[Size[node * 2 + 1]] + T[node * 2 + 1]) % MOD;
    Size[node] = Size[node * 2] + Size[node * 2 + 1];
}
pii getHash(int node, int l, int r, int u, int v) {
    if (u > r || v < l) return {0, 0};
    if (u <= l && r <= v) return {T[node], Size[node]};
    int mid = l + (r - l) / 2;
    pii low = getHash(node * 2, l, mid, u, v);
    pii high = getHash(node * 2 + 1, mid + 1, r, u, v);
    return {(low.fi * h[high.se] + high.fi) % MOD, low.se + high.se};
}
int getPos(int node, int l, int r, int pos) {
    if (l == r) return l;
    int mid = l + (r - l) / 2;
    if (pos <= Size[node * 2]) return getPos(node * 2, l, mid, pos);
    return getPos(node * 2 + 1, mid + 1, r, pos - Size[node * 2]);
}
void update(int node, int l, int r, int pos) {
    if (l == r) {
        T[node] = Size[node] = 0;
        return;
    }
    int mid = l + (r - l) / 2;
    if (pos > mid) update(node * 2 + 1, mid + 1, r, pos);
    else update(node * 2, l, mid, pos);
    Size[node] = Size[node * 2] + Size[node * 2 + 1];
    T[node] = (T[node * 2] * h[Size[node * 2 + 1]] + T[node * 2 + 1]) % MOD;
}
void solve() {
    char c; int l1, l2, m;
    cin >> c >> l1;
    if (c == '?') {
        cin >> l2 >> m;
        int u1 = getPos(1, 1, n, l1);
        int v1 = getPos(1, 1, n, l1 + m - 1);
        int u2 = getPos(1, 1, n, l2);
        int v2 = getPos(1, 1, n, l2 + m - 1);
        cout << (getHash(1, 1, n, u1, v1) == getHash(1, 1, n, u2, v2)
            ? "YES\n" : "NO\n");
    } else update(1, 1, n, getPos(1, 1, n, l1));
}
main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> s; n = sz(s); s = ' ' + s;
    h[0] = 1;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i] - '0';
        h[i] = (h[i - 1] * base) % MOD;
    }
    init(1, 1, n);
    cin >> t; while (t--) solve();
    return 0;
}
