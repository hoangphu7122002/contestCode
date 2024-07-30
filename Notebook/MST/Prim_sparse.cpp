//Weight, Undirected graph

//sparse graph
//complexity O(nlogm)

#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll maxN = 1e3 + 1;
const ll INF = 1e9 + 1;

int n;

struct Edge {
    ll w = INF;
    int v = -1;
    bool operator<(Edge const& other) const {
        return make_pair(w, v) < make_pair(other.w, other.v);
    }
};

vector <Edge> g[maxN];

void prim() {
    ll total_weight = 0;
    vector <bool> used(n + 1, false);
    vector <Edge> min_e(n + 1);

    min_e[1].w = 0;
    set <Edge> q;
    q.insert({0,1});

    for (int i = 1; i <= n; ++i) {
        if (q.empty()) {
            cout << "No MST!" << endl;
            return;
        }

        int u = q.begin()->v;
        used[u] = true;
        total_weight += q.begin()->w;
        q.erase(q.begin());

        if (min_e[u].v != -1) {
            cout << u << " " << min_e[u].v << endl;
        }
        for (auto e : g[u]) {
            int v = e.v;
            ll w = e.w;
            if (!used[v] && w < min_e[v].w) {
                q.erase({min_e[v].w, v});
                min_e[v] = {w,u};
                q.insert({w,v});
            }
        }
    }

    cout << total_weight << endl;
    return ;
}

int main() {
    return 0;
}