/// Created by Zylenox
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define Task "task"
#define Nyaa main
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define bit(i, x) ((x >> i) & 1)
#define sz(x) (int)(x).size()
#define ntest int t; cin >> t; while (t--) solve()
#define __lcm(a, b) (1ll * ((a) / __gcd((a), (b))) * (b))
#define yes cout << "yes\n"
#define no cout << "no\n"
#define int ll
// x << y : x * (2 ^ y)
// x >> y : x / (2 ^ y)
// __builtin_clz(n)) : count the number of first zeros
// __builtin_ctz(n)) : count the number of final zeros
// __builtin_popcount(n) : count the number of digits 1
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void cmin(int &x, int y) { x = (x > y) ? y : x; }
const int N = 1e5 + 10;
int n, m, scc, cnt; vi adj[N], val[N];
int low[N], id[N], num[N];
stack<int> st;
void dfs(int u) {
    st.push(u);
    low[u] = id[u] = ++cnt;
    for (int v : adj[u]) if (!num[v]) {
        if (id[v]) cmin(low[u], id[v]);
        else {
            dfs(v);
            cmin(low[u], low[v]);
        }
    }
    if (low[u] == id[u]) {
        ++scc;
        int v = -1; while (v != u) {
            v = st.top(); st.pop();
            num[v] = scc;
            val[scc].pb(v);
        }
    }
}
Nyaa() {
    cin.tie(nullptr)->sync_with_stdio(false);
    //freopen(Task".inp", "r", stdin);
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u].pb(v);
    }
    for (int i = 1; i <= n; i++) if (!id[i]) dfs(i);
    cout << scc << '\n';
//    for (int i = 1; i <= scc; i++) {
//        cout << sz(val[i]) << '\n';
//        for (int x : val[i]) cout << x << ' ';
//        cout << '\n';
//    }
    return 0;
}
// I wish I was a cat, no school, no work, just meow meow.
/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢆⠣⡀⠀⣀⣀⣤⣤⣤⣶⣶⣶⣶⣶⣶⣶⣶⣶⣦⣤⣤⣤⣄⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣦⣤⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠤⠤⣄⣀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⢿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⣠⠋⣸⣷⣤⡀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⠋⠉⠉⠛⠓⠦⡀⠈⠢⡀⠀⠀⠀⠀⠀⠀⠀⣀⠤⠐⠂⠉⠉⠉⠉⠁⠒⠂⠤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣠⢁⣼⣿⣿⣿⣿⣦⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠛⠛⠛⠉⠉⠁⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢄⡈⢆⠀⠀⠀⠀⠠⠊⠁⠀⠀⠀⠀⣀⣠⣤⠤⠤⠤⠤⣈⠐⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠈⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠢⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠢⣧⠀⠀⡔⠁⠀⠀⠀⣠⣴⡿⠿⠭⠤⣄⡀⠀⠀⠀⠉⢺⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠛⠁⠀⠙⠻⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠑⠤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢧⡰⠀⠀⠀⣠⠞⠋⠀⠀⠀⠀⠀⠀⠙⢦⠀⠀⠀⠀⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢀⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠋⠙⢄⠀⠀⠀⠀⠀⠀⠈⠳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠐⠢⠤⢀⣰⡆⣀⣀⣀⠀⢀⡃⠀⠀⡰⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢀⣴⣿⣿⣿⣿⡿⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⠋⠉⢣⠀⠀⠀⠀⠀⠱⢄⠀⠀⠀⠀⠀⠀⠈⠢⡀⠀⠀⠀⠀⠀⠐⡀⠀⠀⠀⠀⠀⠀⡴⠥⣷⠎⠉⠀⠀⠀⠈⠑⢴⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣿⣿⣿⡟⠁⠀⠀⢠⠃⠀⠀⠀⠀⠀⠈⣹⣿⡿⣿⣿⠿⠟⠛⠋⡟⠁⠀⠀⠀⠀⠀⠀⠱⡀⠀⠀⠀⠀⠈⠳⡀⠀⠀⠀⠀⠀⠀⠈⢢⠀⠀⠀⠀⠀⢠⠀⠀⠀⠀⠀⠀⠀⢀⠇⠀⠀⠀⠀⠀⠀⠀⠀⢣⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⡌⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢛⢿⣿⣿⠟⠀⠀⠀⢀⠇⠀⡞⠀⠀⠀⠀⠀⣿⠏⠀⠀⠀⠀⠀⠀⢠⠇⠀⠀⠀⠀⠀⠀⠀⠀⠙⡄⠀⠀⠀⠀⠀⠙⣦⡀⠀⠀⠀⠀⠀⠀⡑⡄⠀⠀⠀⠀⢳⠀⠀⠀⠀⢀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣄⡀⠀⠀⠀⠀⠀⠀⠀⣀⠊⠀⠀⠀⡐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣠⠶⠋⠁⠀⠀⠀⠀⠎⠀⣸⠃⠀⠀⠀⠀⢰⡟⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣄⠀⠀⠀⠀⠀⠘⢿⣦⡀⠀⠀⠀⠀⠘⡌⢆⠀⠀⠀⠈⢏⠉⠁⠀⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠀⢠⣏⠉⠉⠑⠒⠤⠤⠤⠤⠊⠀⠀⠀⠀⡰⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⡰⠀⢠⣿⠀⠀⠀⠀⠀⣿⠃⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡄⠀⠀⠀⠀⠀⠀⠹⣿⣄⠀⠀⠀⠀⠱⡜⣧⡱⠀⠀⠘⡄⠀⠀⠀⠀⠀⠑⠦⣀⡀⠀⢀⣠⣴⢿⢿⣷⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⡠⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢠⠃⠀⣾⡇⠀⠀⠀⠀⢠⣿⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡈⢆⠀⠀⠀⠀⠀⠹⣿⣦⡀⠀⠀⠀⢱⠬⣷⣅⠀⠀⢣⠀⠀⠀⠀⠀⠀⠀⣸⡿⠋⠉⠁⡿⠈⢮⢻⡻⠿⣿⣶⣒⡒⠒⠒⠂⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⡈⠀⣸⣿⠀⠀⠀⠀⠀⢸⡏⠀⠀⠀⠀⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢧⠸⡄⠀⠀⠀⠀⠀⢹⡄⠉⠇⠂⠤⣀⠃⠘⣿⡄⠀⠈⡆⠀⠀⠀⠀⢠⡾⠋⠀⠀⠀⠀⠇⠀⢸⠧⡝⢦⡀⠀⠀⠀⠉⠐⠒⠂⠀⢀⣀⠲⠖⠊⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢀⠇⠀⡿⡇⠀⠀⠀⠀⠀⡿⡇⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡆⢱⡀⠀⠀⠀⠀⠀⢳⠀⠸⡄⠀⠀⠉⢢⣸⣿⡀⠀⢸⠀⠀⢀⠴⠋⠀⠀⠀⠀⢀⡸⠀⠀⠈⡇⠈⠲⣌⠲⢄⡀⠀⠉⠉⠭⣉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢸⠀⠀⡇⡇⠀⠀⠀⠀⠀⡇⡇⠀⠀⠀⠰⠀⠀⠀⠀⢸⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⠀⣇⠀⠀⠀⠀⠀⠈⡇⠀⠈⠑⠲⢤⣤⣽⡏⢃⠀⠈⡄⠐⠀⠀⠀⠀⠀⠀⠀⣾⠃⠀⠀⠀⢳⠀⠀⠀⠙⠢⣝⡲⢤⣀⣀⠀⠉⠀⠒⠠⠤⠄⠀⠀⢤⠔⠀⠀⠀
⠀⠀⠀⠀⠀⡇⠀⢠⢰⢠⠀⠀⠀⠀⢠⡇⡇⠀⠀⠀⠀⡄⠀⠀⠀⠘⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡆⠸⡄⠀⠀⢸⡀⠀⢻⠀⠀⠀⠀⠀⢫⡩⠵⣮⡆⠀⢱⠐⢄⣀⡀⣀⣀⣀⡾⠃⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⠉⠛⠲⠯⣭⡭⠛⠋⠁⢀⣀⠤⠐⠁⠀⠀⠀⠀
⠀⠀⠀⠀⠀⡇⠀⢸⣸⡘⠀⠀⠀⠀⠀⣧⠃⠀⠀⠀⠀⣇⠀⠀⠀⠀⡟⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢧⠀⣇⠀⠀⢸⡇⠀⠈⡇⠀⣀⠄⠂⠁⠳⣄⠈⢻⠀⠈⡆⠢⢽⣄⢀⣀⡙⢦⡒⠒⠦⢔⡊⠉⠳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢸⡇⡇⠀⠀⠀⣀⣀⣿⣰⠀⠀⠀⠀⢸⠀⠀⠀⠀⣇⠘⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⣿⠀⠀⢸⣿⠀⣀⣷⠊⠀⠀⠀⠀⠀⠀⠉⠉⡇⡀⣧⣤⣼⠿⢇⡤⠀⠑⣇⠐⠒⢒⣡⣀⣱⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⡀⠀⢸⡇⡇⠀⢯⠭⠭⠵⢶⡞⡇⠀⠀⠀⠈⡇⠀⠀⠀⢸⠀⠈⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⣿⠀⠀⢸⣿⡟⠁⢸⠀⠀⠀⠀⠀⢀⣠⣶⣿⣿⣷⢻⡿⠁⠀⠛⠀⠀⠀⠈⣖⢶⣿⣿⡿⠿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⡇⠀⢸⡇⢧⠀⠀⠀⠀⣀⣤⣷⣿⠀⠀⠀⠀⣿⡀⠀⠀⠘⡆⠀⠈⢳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⡏⠀⠀⠊⡻⢸⠀⣼⠀⠀⣠⣶⣿⣿⣿⣿⣟⢛⠉⡎⡁⠀⠀⠀⠀⠀⠀⠀⣘⠀⠀⠀⠀⠀⢰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢃⠀⢸⢹⠸⠀⠀⢰⣿⢿⣛⣿⣽⡦⠀⠀⠀⢹⣷⠀⠀⠀⢱⠀⠀⠀⠳⡀⠀⠀⠰⡀⠀⠀⠀⠀⡼⢰⢧⡀⠀⠀⡇⠸⡎⡇⣴⣿⡿⢛⣿⣿⣿⣿⣿⠸⠀⠇⡇⠀⠀⠀⠀⠀⠀⠀⣿⡆⠀⠀⠀⠀⠘⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠸⡀⠈⢸⠀⠇⠀⠀⠰⠟⠋⠉⣧⠹⡄⠀⠀⠸⣿⢳⡒⠉⠙⡍⠉⠉⠉⠛⣆⠀⠀⠘⢦⡀⠀⢠⢧⡟⠀⢳⡀⢠⠃⢠⢣⢳⡿⠛⢶⣿⣿⣿⣿⣿⣿⠃⡏⠀⢡⠀⠀⠀⠀⢀⠇⢸⡏⣿⠀⠀⠀⠀⠀⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢃⠀⡘⡀⢸⠀⠀⠀⠀⠀⠀⠸⡄⢧⠀⠀⠀⣿⠀⠱⡄⠀⠘⡄⠀⠀⠀⠈⠳⡄⠀⠈⠻⡢⣼⣿⠁⠀⠀⠑⣼⠀⢸⡎⠀⠀⠀⠀⠻⢿⣿⣿⣿⠿⠂⢣⠀⢺⠀⠀⠀⠐⠋⣠⣿⠇⢹⡆⠀⠀⠀⠀⠘⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠈⢆⡇⡇⠀⣆⠀⠀⠀⠀⠀⠀⢳⡈⢧⠀⠀⢸⠀⠀⠈⠢⡀⠙⣄⠀⠀⠒⠒⠨⠳⢄⣀⡼⠫⣙⡦⢄⣀⠀⠈⠳⢯⠁⠀⠀⠀⠀⠀⠈⠉⠁⠀⠀⠀⢸⠀⢸⠀⠀⣾⣐⡴⠟⠉⠀⠀⣧⠀⠀⠀⠀⠀⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠘⣇⢿⡀⢸⡄⠀⠀⠀⠀⠀⠈⢧⠘⢆⠀⠘⡇⠀⠀⠀⠈⠓⠬⣢⡀⠀⠀⠀⠀⠐⠉⠑⠲⢬⠷⣦⣞⡉⠒⠲⠿⠭⠶⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡀⢸⠀⣰⣿⣿⣄⠀⠀⠀⠀⢿⠀⠀⠀⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢀⣸⡼⣗⢺⣿⡛⠛⠛⠛⠲⢦⢸⣧⠈⢆⠀⢱⣄⠀⠀⠀⠀⠀⠀⣉⣑⣢⣤⣤⡤⠀⠀⢠⢇⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⣸⢰⣿⡏⢸⣿⣧⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⢱⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⡶⠋⠑⡌⡟⣿⡿⣧⠀⠀⠀⠀⠀⠀⢻⣷⡈⢣⠈⣿⣷⣤⣴⣿⠿⠿⠛⠟⠛⠉⠀⠀⠀⠠⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⣿⢿⣿⡇⣿⣿⣿⣧⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣰⠋⠀⠀⠀⠇⢰⡇⢧⠹⣧⠀⠀⠀⠀⠀⠀⢻⣷⣄⠳⡹⣿⣸⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⡿⠘⣿⣷⣿⣿⣿⣿⣦⠀⠘⣿⡆⠠⡀⠀⠀⠀⠈⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⡀⠠⠁⠀⠀⠀⠀⠸⡘⣇⢸⠀⠘⣷⡀⠀⠀⠀⠀⠀⢻⡎⠢⡙⢿⣿⢿⠙⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⡇⡇⠀⣿⣿⣿⣿⣿⠿⠛⠀⠀⣿⣧⠀⠱⡀⠀⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠠⣾⢛⣷⠶⠀⠀⠀⠀⠀⢱⠘⣼⠀⠀⣿⡷⣄⠀⠀⠀⠀⠀⠹⡄⠙⢮⡹⣇⠉⣦⣵⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠂⠀⠀⠀⠀⠀⣠⣾⣦⢁⡇⢰⣿⡟⠋⠉⠀⠀⠀⠀⠀⢸⠈⣇⠀⠘⣆⠀⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⣿⠟⠸⠀⠀⠀⠀⠀⠀⣾⣧⢹⡄⢠⡟⣷⡘⢦⡀⠀⠀⠀⠀⠹⡄⠀⠈⠪⣷⢽⠀⠻⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠤⠐⠀⠀⠀⠀⠀⠀⠀⢀⠔⠁⢸⣿⢸⠀⠸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠸⠀⠘⢆⠀⠈⢷⡀⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠁⠀⠀⠀⠀⠀⠀⠀⢰⠛⣿⣇⠹⣼⠃⠹⣷⠀⠙⢦⠀⠀⠀⠀⠙⣄⠀⠀⠈⢹⠿⣦⣈⠑⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⠁⠀⠀⠈⡇⣾⠀⠀⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠈⢿⣦⡀⠀⠈⢆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⡌⠀⠸⣿⣷⡘⢦⡀⠹⡇⠀⠀⢹⣦⡀⠀⠀⠈⢢⡀⠀⢸⠀⠈⠉⠛⠦⣭⡙⠓⠶⢤⠤⣠⣤⣀⣀⣀⣀⣀⣀⣀⡀⠀⣀⠜⠁⠀⠀⠀⠀⢰⢣⣧⡀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠙⢿⣦⡀⠀⠳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⠃⠀⣸⣿⡿⣿⠶⣝⢦⣽⣆⠀⠀⢿⣏⠲⢤⡀⠀⠙⠢⣼⡀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡄⠘⣿⡄⠀⠀⢘⣿⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⡼⡘⠋⠳⣄⢸⡀⠀⠀⠀⡆⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠘⣎⠢⣄⠘⢦⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⡎⠀⢠⣿⡟⠀⠈⠳⣮⣹⣿⠛⢧⡄⠈⢻⡀⠀⠉⠓⠦⢤⣈⣙⡓⠦⣄⣀⣀⡀⠀⠀⠀⢧⠀⠸⡷⠀⣴⠟⢿⡀⠀⠀⠀⠀⠀⠀⠀⣀⡴⡿⣹⠃⠀⠀⠘⢧⡇⠀⠀⠀⡇⠀⠀⠀⠀⡇⠀⠀⠀⢀⣀⣀⣀⣀⣀⣈⣆⠀⠑⢤⡙⢿⣷⣦⣄⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢰⠀⢠⣿⡟⠀⠀⠀⠀⠈⣿⡟⠀⠀⠙⣦⡀⠱⡄⠀⠀⠀⠀⠀⢻⠉⠉⠉⠉⠉⠁⠀⠀⠀⢸⠀⠀⢱⡞⠁⠀⠀⠉⠓⠶⢤⣄⣀⡠⠞⠁⣰⡿⠁⠀⠀⠀⠀⠨⡇⠀⠀⠀⡇⠀⠀⠀⠀⣿⠁⠈⠉⠁⠀⠀⠀⠀⠀⠀⠉⠳⢄⠀⠈⠲⣿⣿⣿⣿⣶⣤⣀⠀
⠀⠀⠀⠀⠀⠀⢠⢃⠔⣻⡿⠀⠀⠀⠀⠀⢰⣿⠀⡇⠀⢠⣿⣿⠦⣘⢦⡀⠀⠀⠀⠸⡦⠴⠶⠶⠶⠶⠶⠶⠶⠞⠒⠺⣏⠀⠀⠀⠀⠀⠀⢰⡟⠉⠀⠑⣶⣼⠟⠀⠀⠀⠀⠀⠀⢠⡇⠀⠀⢠⠁⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠣⡀⠀⠀⠙⠿⣿⣿⡧⠈⠓
⠀⠀⠀⠀⠀⠀⡞⠀⣰⣿⠁⠀⠀⠀⠀⠀⢸⡏⠀⡇⠀⢸⣿⣿⠀⠈⠙⠛⠲⠤⡀⠀⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡆⠀⠀⠀⠀⢠⣏⡀⠀⢠⡴⠟⣷⡀⠀⠀⠀⠀⠀⠀⣸⢇⠀⠀⣸⠀⠀⠀⠀⡀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠱⠀⠀⠀⠀⠈⠻⢿⡀⠀
⠀⠀⠀⠀⠀⡜⠀⢠⢻⠇⠀⠀⠀⠀⠀⠀⢸⠃⠀⢣⠀⢸⣿⢿⠀⠀⠀⢀⠀⠀⠀⠀⡞⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣷⡀⠀⠀⠀⣿⣿⣿⣦⣀⣀⣴⣿⣷⡄⠀⠀⠀⠀⢠⣿⠈⢦⠀⡇⠀⠀⠀⢸⡇⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠱⠀⠀⠀⠀⠀⠀⠙⢦
⠀⠀⠀⠀⢰⠀⠠⠃⡞⠀⠀⠀⠀⠀⠀⠀⣾⠀⠀⠈⡆⡿⣿⠘⡇⠀⠀⣨⠀⠀⠀⠀⢷⡹⡀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣧⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⢀⣾⡇⠠⡈⢠⠃⠀⠀⠀⢸⣧⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢠⠃⡠⠃⢀⡇⠀⠀⠀⠀⢀⡄⠀⡇⠀⠀⠀⢸⡇⡏⠀⢧⠀⠀⣿⡆⠀⠀⠀⠘⡗⣝⣄⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣀⣼⣿⣿⣿⣿⡿⠟⠉⢿⣿⣿⣿⣿⣆⢀⣾⣿⠃⠀⢡⡏⠀⠀⠀⠀⢸⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢆⠀⠀⠀⠀⠀⠀
⠀⠀⢀⠆⡰⠁⠀⢸⠁⠀⠀⠀⠀⢸⡇⠀⡇⠀⠀⠀⠀⣧⡇⠀⠸⡀⠀⣿⣷⡀⠀⠀⠀⢹⡀⠙⠳⠦⣄⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⡏⠀⢀⡼⠀⠀⠀⠀⠀⣾⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣦⡀⠀⠀⠀⠀
⠀⠀⡌⡐⠁⠀⠀⡾⠀⠀⠀⠀⠀⢸⢻⠀⣧⠀⠀⠀⠀⣾⡇⠀⠀⡇⠀⢻⣿⣧⠀⠀⠀⠀⢳⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⣀⣀⠀⣼⣿⣿⣿⣿⣿⡿⠀⢀⣾⠃⠀⠀⠀⠀⣰⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡝⢦⡀⠀⠀
⠀⡰⡜⠁⠀⠀⢀⡇⠀⠀⠀⠀⠀⡏⠘⡇⢹⠀⠀⠀⢸⣿⢸⠀⠀⠘⡄⠘⣿⣿⣧⠀⠀⠀⠀⢣⡀⠀⠀⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠿⣿⡟⠻⣿⣿⣿⣿⣿⣿⠃⣠⣿⠏⠀⠀⠀⠀⢀⣿⣿⠇⠀⠀⢠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹⣆⡙⠢⡀
⢰⡵⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⢠⠇⠀⢳⡘⡆⠀⢀⠇⢻⡼⡀⠀⠀⠱⡀⠹⡟⣿⣧⡀⠀⠀⠀⠳⡀⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀⠀⢿⣿⠀⢸⣿⣿⣿⣿⣧⣾⣿⠏⠀⠀⠀⠀⢀⣾⣿⣿⡄⠀⠀⢸⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⠤⠒⠉⠀⠀⢳⠀⠈
*/
// ¿Qué miras, bobo