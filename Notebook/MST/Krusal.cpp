#include <bits/stdc++.h>
using namespace std;

//O(mlogm + mlogn)

struct Edge {
    int u, v, c;
    Edge(int _u, int _v, int _c): u(_u), v(_v), c(_c) {};

    bool operator<(Edge const& other) {
        return c < other.c;
    }
};

struct Dsu {
    vector <int> par;
    vector <int> rank;

    void init(int n) {
        par.resize(n + 5, 0);
        rank.resize(n + 5, 0);

        for (int i = 1; i <= n; i++) {
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
        if (rank[u] < rank[v]) swap(u, v);
        par[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
        return true;
    }

} dsu;

int n, m, total_weight = 0;
vector <Edge> edges;

void kruskal() {
    dsu.init(n);
    sort(edges.begin(), edges.end());

    for (auto e : edges) {
        if (!dsu.join(e.u,e.v)) continue;
        total_weight += e.c;
    }

    cout << total_weight << endl;
}