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
const int NUMBEROFNODES = 1000005;
struct Trie{
    struct Node{
        int child[26];
        int exist, cnt;
    } nodes[NUMBEROFNODES];

    int cur; // Hiện trong trie đang có bao nhiêu đỉnh
    Trie() : cur(0) { // Tạo nút gốc cho Trie là đỉnh 0 khi khởi tạo Trie
        memset(nodes[0].child, -1, sizeof(nodes[cur].child));
        nodes[0].exist = nodes[0].cnt = 0;
    };

    int new_node() { // Tạo và trả về giá trị của đỉnh mới được tạo ra
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur;
    }

    void add_string(string s) {
        int pos = 0;
        for (auto f : s) {
            int c = f - 'a';
            if (nodes[pos].child[c] == -1) { // Nếu cạnh tương ứng chữ cái c
                                             // chưa tồn tại thì ta tạo ra đỉnh mới
                nodes[pos].child[c] = new_node();
            }
            pos = nodes[pos].child[c];
            nodes[pos].cnt++; // Có thêm một xâu trong trie có tiền tố
                              // là xâu được thể hiện bằng đỉnh hiện tại
        }
        nodes[pos].exist++; // Đã tìm được đỉnh tương ứng với xâu s,
                            // ta tăng biến exist của đỉnh lên 1
    }

    bool delete_string_recursive(int pos, string& s, int i) { // Trả về liệu đỉnh pos
                                                              // có bị xóa đi hay không
        if (i != (int)s.size()) { // Nếu chưa đến đỉnh tương ứng với xâu s
                                  // thì tiếp tục đệ quy xuống dưới
            int c = s[i] - 'a';
            bool isChildDeleted = delete_string_recursive(nodes[pos].child[c], s, i + 1);
            if (isChildDeleted) nodes[pos].child[c] = -1; // Nếu đỉnh con tương ứng bị xóa thì
                                                          // ta gán lại đỉnh tương ứng bằng -1
        }
        else nodes[pos].exist--; // Nếu đã đến đỉnh tương ứng với xâu s
                                 // thì ta giảm biến exist của đỉnh đi 1

        if (pos != 0) { // Nếu đỉnh đang xét không phải gốc thì ta giảm biến cnt của đỉnh đi 1
                        // và kiểm tra đỉnh có bị xóa đi hay không
                        // Đỉnh bị xóa nếu không còn xâu nào đi qua nó, nói cách khác là
                        // không còn xâu nào có tiền tố là xâu được thể hiện bởi đỉnh pos
            nodes[pos].cnt--;
            if (nodes[pos].cnt == 0) return true;
        }
        return false;
    }

    void delete_string(string s) {
        if (find_string(s) == false) return; // Kiểm tra xâu s có trong
                                             // trie hay không
        delete_string_recursive(0, s, 0); // Gọi hàm đệ quy xóa xâu s khỏi trie
    }

    bool find_string(string s) {
        int pos = 0;
        for (auto f : s) {
            int c = f - 'a';
            if (nodes[pos].child[c] == -1) return false;
            pos = nodes[pos].child[c];
        }
        return (nodes[pos].exist != 0); // Kiểm tra có xâu nào
                                        // kết thúc tại đỉnh này hay không
    }
};
Trie T;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    int n, mx = 0; string s; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        T.add_string(s);
        mx = max(mx, sz(s));
    }
    cout << n + 2 * T.cur - mx;
    return 0;
}
