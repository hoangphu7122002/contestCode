#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 1;
int lab[maxN];

int find_set(int v) {
    return lab[v] < 0 ? v : lab[v] = find_set(lab[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (lab[a] > lab[b]) swap(a, b);
        lab[a] += lab[b];
        lab[b] = a;
    }
}

int n,m;

struct Edge {
    int u;
    int v;
    ll c;

    Edge(int u, int v, ll c) : u(u), v(v), c(c) {}
};

bool cmp(const Edge& a, const Edge& b) {
    return a.c < b.c;
}

int main() {
    // freopen("inp.txt", "r", stdin);
    memset(lab, -1, sizeof(lab));
    cin >> n >> m;
    vector <Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u,v;
        ll c;
        cin >> u >> v >> c;
        edges.push_back(Edge(u,v,c));
    }

    sort(edges.begin(),edges.end(),cmp);
    ll cost = 0;
    for (auto e : edges) {
        int u = e.u;
        int v = e.v;
        ll c = e.c;
        // cout << u << " " << v << " " << c << "\n";
        if (find_set(u) != find_set(v)) {
            cost += c;
            union_sets(u, v);
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << lab[i] << " ";
    // }
    // cout << "\n";
    if (lab[find_set(1)] != -n) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << cost << "\n";
    }

    return 0;
}