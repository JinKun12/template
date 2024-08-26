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
const int NUMBEROFNODES = 5000001;
const int LG = 30;
struct Trie{
    struct Node{
        int child[2];
        int exist, cnt;
    } nodes[NUMBEROFNODES];

    int cur;
    Trie() : cur(0) {
        memset(nodes[0].child, -1, sizeof(nodes[cur].child));
        nodes[0].exist = nodes[0].cnt = 0;
    };

    int new_node() {
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur;
    }

    void add_number(int x) {
        int pos = 0;
        for (int i = LG; i >= 0; i--) {
            int c = (x >> i) & 1;
            if (nodes[pos].child[c] == -1) nodes[pos].child[c] = new_node();
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }

    void delete_number(int x) {
        if (find_number(x) == false) return;
        int pos = 0;
        for (int i = LG; i >= 0; i--) {
            int c = (x >> i) & 1;
            int tmp = nodes[pos].child[c];
            nodes[tmp].cnt--;
            if (nodes[tmp].cnt == 0) {
                nodes[pos].child[c] = -1;
                return;
            }
            pos = tmp;
        }
        nodes[pos].exist--;
    }

    bool find_number(int x) {
        int pos = 0;
        for (int i = LG; i >= 0; i--) {
            int c = (x & (1 << i) ? 1 : 0);
            if (nodes[pos].child[c] == -1) return false;
            pos = nodes[pos].child[c];
        }
        return (nodes[pos].exist != 0);
    }

    string find_kth_string(int k) {
        int pos = 0;
        string res = "";
        while (true) {
            if (nodes[pos].exist >= k) break;
            k -= nodes[pos].exist;
            for (int i = 0; i < 10; i++) if (nodes[pos].child[i] != -1) {
                int nxt = nodes[pos].child[i];
                if (nodes[nxt].cnt >= k) {
                    res += char(i + '0');
                    pos = nxt;
                    break;
                }
                k -= nodes[nxt].cnt;
            }
        }
        return res;
    }
};
Trie T;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    int n; cin >> n;
    for (int i = 0, type, x; i < n; i++) {
        cin >> type >> x;
        if (type == 1) T.add_number(x);
        else {
            string s = T.find_kth_string(x);
            int ans = 0;
            for (int i = 0, j = 30; i < 31; i++, j--)
                if (s[i] == '1')
                    ans += (1 << j);
            cout << ans << '\n';
        }
    }
    return 0;
}
