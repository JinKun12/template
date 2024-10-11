struct DSU {
    struct Data {
        int a, b, sza, parb;
    };
    vector<Data> history;
    int cnt;
    int par[N], sz[N];
    void make_set(int u) {
        par[u] = u;
        sz[u] = 1;
    }
    void init(int n) {
        cnt = n;
        for (int i = 1; i <= n; i++) make_set(i);
        history.clear();
    }
    int Find(int u) {
        return par[u] == u ? u : par[u] = Find(par[u]);
    }
    bool Merge(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        history.pb({u, v, sz[u], par[v]});
        par[v] = u;
        sz[u] += sz[v];
        --cnt;
        return true;
    }
    void roll_back(int pos) {
        while (sz(history) - 1 > pos) {
            Data tmp = history.back();
            history.pop_back();
            par[tmp.b] = tmp.parb;
            sz[tmp.a] = tmp.sza;
            ++cnt;
        }
    }
} dsu;
