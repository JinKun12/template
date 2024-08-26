/// Created by Zylenox`
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
int n, m, k, ans = 0;
const int N = 100001;
int T[2 * N];
pair<pii, int> l[2 * N];
struct Data {
    int id, from, to;
}; Data ngang[N], doc[N];
int xngang[2 * N], xdoc[2 * N];
int slngang, sldoc, lng;
void init(Data a[], int &sl) {
    sort(a + 1, a + sl + 1, [](Data p, Data q) {
        if (p.id != q.id) return p.id < q.id;
        if (p.from != q.from) return p.from < q.from;
        return p.to < q.to;
    });
    a[sl+1].id = a[sl].id + 1;
    Data doan = a[1];
    int u = 0;
    for (int i = 2; i <= sl + 1; i++) {
        if (a[i].id == doan.id && a[i].from <= doan.to + 1) doan.to = a[i].to;
        else {
            a[++u] = doan;
            doan = a[i];
        }
    }
    sl = u;
    for (int i = 1; i <= u; i++)
        ans += a[i].to - a[i].from + 1;
}
void makePoint() {
    int sl = 0;
    for (int i = 1; i <= slngang; i++) {
        l[++sl] = {{ngang[i].from, ngang[i].id}, 1};
        l[++sl] = {{ngang[i].to + 1, ngang[i].id}, -1};
    }
    l[++sl] = {{n + 2, 0}, 0};
    sort(l + 1, l + sl + 1);
}
void update(int x, int val) {
    for (; x <= 2 * N; x += x & -x) T[x] += val;
}
int get(int x) {
    int res = 0;
    for (; x; x -= x & -x) res += T[x];
    return res;
}
int pos(int x) {
    return lower_bound(xngang + 1, xngang + lng + 1, x) - xngang;
}
main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y; char c;
        cin >> x >> y >> c;
        xngang[++lng] = x;
        if (c == 'N') doc[++sldoc] = Data({y, x, m});
        if (c == 'S') doc[++sldoc] = Data({y, 1, x});
        if (c == 'E') ngang[++slngang] = Data({x, y, n});
        if (c == 'W') ngang[++slngang] = Data({x, 1, y});
    }
    xngang[++lng] = m;
    xngang[++lng] = 1;
    init(ngang, slngang);
    init(doc, sldoc);
    makePoint();
    sort(xngang + 1, xngang + lng + 1);
    int j = 1;
    for (int i = 1; i <= sldoc; i++) {
        Data doan = doc[i];
        while (l[j].fi.fi <= doan.id) {
            update(pos(l[j].fi.se), l[j].se);
            j++;
        }
        ans -= get(pos(doan.to)) - get(pos(doan.from) - 1);
    }
    cout << ans;
    return 0;
}
