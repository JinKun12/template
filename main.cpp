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
#define bit(i, x)((x >> i) & 1)
#define sz(x) (int)(x).size()
#define int ll
// Codeforces
#define ntest int t; cin >> t; while (t--) solve()
#define yes cout << "yes\n"
#define no cout << "no\n"
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 1e6 + 10;
const int LG = 20 + 5;
const int INF = 2e18;
int n, a[N];
struct BIT {
    int n, T[N];
    void add(int x, int val) {
        for (; x <= n; x += x & -x) T[x] += val;
    }
    int sum(int x) {
        int res = 0;
        for (; x; x -= x & -x) res += T[x];
        return res;
    }
};
struct ST {
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
};
struct Trie {
    struct Node {
        int child[26];
        int exist, cnt;
    } nodes[N];
    int cur;
    Trie() : cur(0) {
        memset(nodes[0].child, -1, sizeof(nodes[cur].child));
        nodes[0].exist = nodes[0].cnt = 0;
    }
    int new_node() {
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur;
    }
    void add_string(string s) {
        int pos = 0;
        for (auto f : s) {
            int c = f - 'a';
            if (nodes[pos].child[c] == -1)
                nodes[pos].child[c] = new_node();
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }
    bool delete_string_recursive(int pos, string &s, int i) {
        if (i != sz(s)) {
            int c = s[i] - 'a';
            bool isChildDeleted = delete_string_recursive(nodes[pos].child[c], s, i + 1);
            if (isChildDeleted) nodes[pos].child[c] = -1;
        }
        else nodes[pos].exist--;
        if (pos != 0) {
            nodes[pos].cnt--;
            if (nodes[pos].cnt == 0) return true;
        }
        return false;
    }
    void delete_string(string s) {
        if (find_string(s) == false) return;
        delete_string_recursive(0, s, 0);
    }
    bool find_string(string s) {
        int pos = 0;
        for (auto f : s) {
            int c = f - 'a';
            if (nodes[pos].child[c] == -1) return false;
            pos = nodes[pos].child[c];
        }
        return (nodes[pos].exist != 0);
    }
};
struct DSU {
    int par[N], sz[N];
    void make_set(int u) {
        par[u] = u;
        sz[u] = 1;
    }
    void init(int n) {
        for (int i = 1; i <= n; i++) make_set(i);
    }
    int Find(int u) {
        // return par[u] ? par[u] = Find(par[u]) : u;
        return par[u] == u ? u : par[u] = Find(par[u]);
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
    bool Merge(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};
struct IJK {
    struct Edge {
        int u, v, w;
    }; vector<Edge> adj[N];
    int d[N];
    void init(int s) {
        fill(d, d + N, INF);
        priority_queue<pii> pq;
        pq.push({0, s});
        while (!pq.empty()) {
            int u = pq.top().se;
            int w = -pq.top().fi;
            pq.pop();
            if (w > d[u]) continue;
            for (auto x : adj[u]) {
                if (d[x.v] > w + x.w) {
                    d[x.v] = w + x.w;
                    pq.push({-d[x.v], x.v});
                }
            }
        }
    }
};
struct RMQ {
    int T[LG][N];
    void process() {
        for (int i = 1; i <= n; i++) T[0][i] = a[i];
        for (int j = 1; j <= LG; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                T[j][i] = min(T[j - 1][i], T[j - 1][i + (1 << (j - 1))]);
    }
    int query(int l, int r) {
        int k = __lg(r - l + 1);
        return min(T[k][l], T[k][r - (1 << k) + 1]);
    }
};
struct LCA {
    vector<int> adj[N];
    int h[N], par[N][LG];
    void dfs(int u, int p) {
        h[u] = h[p] + 1;
        par[u][0] = p;
        for (int v : adj[u])
            if (v != p)
                dfs(v, u);
    }
    int get(int u, int v) {
        if (h[u] != h[v]) {
            if (h[u] < h[v]) swap(u, v);
            int k = h[u] - h[v];
            for (int j = 0; (1 << j) <= k; j++)
                if (k >> j & 1)
                    u = par[u][j];
        }
        if (u == v) return u;
        int k = __lg(h[u]);
        for (int j = k; j >= 0; j--) {
            if (par[u][j] != par[v][j])
                u = par[u][j], v = par[v][j];
        }
        return par[u][0];
    }
};
main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    return 0;
}
