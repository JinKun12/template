#include<iostream>
#include<cstring>
#include<cstdio>
#define N (100000 + 1000)
#define M (500000 + 1000)
using namespace std;
struct Edge {
    int from, to, next;
} edge[M << 1];
int n, m, u, v, head[N], num_edge;
int Dfn[N], Low[N], dfs_num, Cut[N];
long long size[N], ans[N];
void add(int u, int v) {
    edge[++num_edge].from = u;
    edge[num_edge].to = v;
    edge[num_edge].next = head[u];
    head[u] = num_edge;
}
void Tarjan(int x, int fa) {
    long long son_num = 0, sum = 0;
    size[x] = 1;
    Dfn[x] = Low[x] = ++dfs_num;
    for (int i = head[x]; i; i = edge[i].next) {
        if (!Dfn[edge[i].to]) {
            son_num++;
            Tarjan(edge[i].to, x);
            size[x] += size[edge[i].to];
            Low[x] = min(Low[x], Low[edge[i].to]);

            if (Low[edge[i].to] >= Dfn[x]) {
                Cut[x] = true;
                ans[x] += sum * size[edge[i].to];
                sum += size[edge[i].to];
            }
        } else if (Dfn[x] > Dfn[edge[i].to] && edge[i].to != fa) {
            Low[x] = min(Low[x], Dfn[edge[i].to]);
        }
    }
    if (fa == 0 && son_num == 1) {
        Cut[x] = false;
    }
    if (Cut[x]) {
        ans[x] += sum * (n - sum - 1);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; ++i)
        if (!Dfn[i])
            Tarjan(i, 0);
    for (int i = 1; i <= n; ++i) {
        printf("%lld\n", (long long)(ans[i] + n - 1) * 2);
    }
    return 0;
}
