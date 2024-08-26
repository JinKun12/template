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
#define int ll
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int maxn = 100001, LG = 16;
int n, k, a[maxn], st[LG + 1][maxn];
void process() {
    for (int i = 1; i <= n; i++) st[0][i] = a[i];
    for (int j = 1; j <= LG; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
int query(int l, int r) {
    int k = __lg(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}
int bsLeft(int l, int r, int i) {
    int ans = i;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (query(mid, i) <= a[i] + k)
            ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}
int bsRight(int l, int r, int i) {
    int ans = i;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (query(i, mid) <= a[i] + k)
            ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    process();
    for (int i = 1; i <= n; i++)
        cout << bsRight(i, n, i) - bsLeft(1, i, i) + 1 << ' ';
    return 0;
}
