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
const int N = 10001;
int child[N * 50][26], cnt;
bool isEnd[N * 50];
int n, m;
void add(string &s) {
    int u = 0;
    for (char c : s) {
        int k = c - 'a';
        if (!child[u][k]) child[u][k] = ++cnt;
        u = child[u][k];
    }
    isEnd[u] = 1;
}
bool query(string &s) {
    int u = 0;
    for (char c : s) {
        int k = c - 'a';
        if (!child[u][k]) return 0;
        u = child[u][k];
    }
    return isEnd[u];
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        add(s);
    }
    cin >> m;
    while (m--) {
        string s; cin >> s;
        cout << query(s) << '\n';
    }
    return 0;
}
