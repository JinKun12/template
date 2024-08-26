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
int n, m, a[N];
struct st {
    int T1[N], T2[N], id[N], vt[N];
    void update(int node, int l, int r, int pos, int val) {
        if (r < pos || l > pos) return;
        if (l == r) {
            T1[node] = val;
            T2[node] = val;
            id[l] = node;
            vt[l] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (mid < pos) update(node * 2 + 1, mid + 1, r, pos, val);
        else update(node * 2, l, mid, pos, val);
        T1[node] = min(T1[node * 2], T1[node * 2 + 1]);
        T2[node] = max(T2[node * 2], T2[node * 2 + 1]);
    }
    void update(int pos, int val) {
        int node = id[pos];
        vt[pos] = val;
        T1[node] = val;
        T2[node] = val;
        while (node > 1) {
            node /= 2;
            T1[node] = min(T1[node * 2], T1[node * 2 + 1]);
            T2[node] = max(T2[node * 2], T2[node * 2 + 1]);
        }
    }
    int getMin(int node, int l, int r, int u, int v) {
        if (u > r || v < l) return 2e18;
        if (u <= l && r <= v) return T1[node];
        int mid = l + (r - l) / 2;
        int low = getMin(node * 2, l, mid, u, v);
        int high = getMin(node * 2 + 1, mid + 1, r, u, v);
        return min(low, high);
    }
    int getMax(int node, int l, int r, int u, int v) {
        if (u > r || v < l) return -2e18;
        if (u <= l && r <= v) return T2[node];
        int mid = l + (r - l) / 2;
        int low = getMax(node * 2, l, mid, u, v);
        int high = getMax(node * 2 + 1, mid + 1, r, u, v);
        return max(low, high);
    }
};;
st T;
main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], T.update(1, 1, n, a[i], i);
    while (m--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 1) {
            int tx = T.vt[a[x]], ty = T.vt[a[y]];
            T.update(a[x], ty);
            T.update(a[y], tx);
            swap(a[x], a[y]);
        } else {
            if (x > y) swap(x, y);
            int tmp = T.getMax(1, 1, n, x, y) - T.getMin(1, 1, n, x, y);
            cout << ((tmp == y - x) ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
