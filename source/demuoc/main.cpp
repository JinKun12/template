/// Created by Zylenox
#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define Task "task"
#define fi first
#define se second
#define push_back pb
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<ll, ll> pll;
const int maxn = 3000000;
const int MOD = 123456789;
int uoc[maxn + 1], cnt[maxn + 1];
void sieve() {
    for (int i = 1; i <= maxn; i++) uoc[i] = 1;
    for (int i = 2; i <= maxn; i++)
        if (uoc[i] == 1)
            for (int j = i; j <= maxn; j += i)
                uoc[j] = i;
}
void fact(int x) {
    while (x > 1) {
        cnt[uoc[x]]++;
        x /= uoc[x];
    }
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    sieve();
    int n; cin >> n;
    for (int i = 0, a; i < n; i++)
        cin >> a, fact(a);
    ll ans = 1;
    for (int i = 2; i <= maxn; i++)
        ans = (ans * (cnt[i] + 1)) % MOD;
    cout << ans << '\n';
    return 0;
}
