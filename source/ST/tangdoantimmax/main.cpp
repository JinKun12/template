/// Created by Zylenox
#pragma GCC optimize("O3","unroll-loops")
//#pragma GCC target("avx2")
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
struct stMax {
    int T[N], id[N];
    void init(int node, int l, int r) {
        if (l == r) {
            T[node] = a[l];
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
        T[node] = a[pos] = val;
        while (node > 1) {
            node /= 2;
            T[node] = max(T[node * 2], T[node * 2 + 1]);
        }
    }
};;
struct stMin {
    int T[N], id[N], delta[N];
    void init(int node, int l, int r) {
        if (l == r) {
            T[node] = a[l];
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
        return delta[node] + max(low, high);
    }
    void update(int node, int l, int r, int u, int v, int w) {
        if (u > r || v < l) return;
        if (u <= l && r <= v) {
            delta[node] += w;
            T[node] += w;
            return;
        }
        int mid = l + (r - l) / 2;
        update(node * 2, l, mid, u, v, w);
        update(node * 2 + 1, mid + 1, r, u, v, w);
        T[node] = delta[node] + max(T[node * 2], T[node * 2 + 1]);
    }
};;
stMin T;
main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    T.init(1, 1, n);
    while (m--) {
        int t, u, v, w; cin >> t >> u >> v;
        if (t == 1) {
            cin >> w;
            T.update(1, 1, n, u, v, w);
        } else cout << T.get(1, 1, n, u, v) << '\n';
    }
    return 0;
}
