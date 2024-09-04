#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>

struct Edge {
    int u, v;
    long double c;
    Edge(int _u, int _v, long double _c): u(_u), v(_v), c(_c) {};
};

struct Dsu {
    vector<int> par;
    vector<int> rank;
    void init(int n) {
        par.resize(n + 1, 0);
        rank.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        if (rank[u] < rank[v]) swap(u,v);
        if (rank[u] == rank[v]) rank[u] += 1;
        par[v] = u;
        return true;
    }
} dsu;

vector < Edge > edges;

int x[151];
int y[151];

long double euclid(int i, int j) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

int main() {
    // freopen("inp.txt","r",stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    long double w,c;
    cin >> w >> c;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) edges.push_back({i,j,c * euclid(i,j)});
        }
    }

    dsu.init(n);

    sort(edges.begin(), edges.end(), [](Edge & x, Edge & y) {
        return x.c < y.c;
    });


    
    long double road = 0;
    long double ans = n * w;
    for (auto e : edges) {
        // Nếu không hợp nhất được 2 đỉnh u và v thì bỏ qua
        if (!dsu.join(e.u, e.v)) continue;

        // Nếu hợp nhất được u, v ta thêm trọng số cạnh vào kết quả
        ans = min(ans, ans - w + e.c);
        road += e.c;
    }

    ans = min(ans,road);

    cout << fixed << setprecision(9) << ans;    

    return 0;
}