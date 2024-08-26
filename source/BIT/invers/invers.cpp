/// Created by Zylenox
#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define Task "task"
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define int ll
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int maxn = 1000001;
int n, a[maxn], bit_arr[maxn];
int sum(int x) {
    int res = 0;
    while (x) {
        res += bit_arr[x];
        x -= x & (-x);
    }
    return res;
}
void add(int x, int val) {
    while (x <= n) {
        bit_arr[x] += val;
        x += x & (-x);
    }
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        ans += sum(a[i] - 1);
        add(a[i], 1);
    }
    cout << ans;
    return 0;
}
