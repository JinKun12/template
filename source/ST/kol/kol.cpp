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
int n, m, z;
int T[N], lz[N];
void push(int node) {
    lz[node * 2] += lz[node];
    lz[node * 2 + 1] += lz[node];
    T[node * 2] += lz[node];
    T[node * 2 + 1] += lz[node];
    lz[node] = 0;
}
int get(int node, int l, int r, int u, int v) {
    if (u > r || v < l) return -2e18;
    if (u <= l && r <= v) return T[node];
    int mid = l + (r - l) / 2;
    if (lz[node]) push(node);
    int low = get(node * 2, l, mid, u, v);
    int high = get(node * 2 + 1, mid + 1, r, u, v);
    return max(low, high);
}
void update(int node, int l, int r, int u, int v, int val) {
    if (u > r || v < l) return;
    if (u <= l && r <= v) {
        lz[node] += val;
        T[node] += val;
        return;
    }
    int mid = l + (r - l) / 2;
    if (lz[node]) push(node);
    update(node * 2, l, mid, u, v, val);
    update(node * 2 + 1, mid + 1, r, u, v, val);
    T[node] = max(T[node * 2], T[node * 2 + 1]);
}
main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m >> z;
    while (z--) {
        int u, v, w; cin >> u >> v >> w;
        update(1, 1, n, u + 1, v, w);
        if (get(1, 1, n, u + 1, v) <= m) cout << "T\n";
        else {
            update(1, 1, n, u + 1, v, -w);
            cout << "N\n";
        }
    }
    return 0;
}
