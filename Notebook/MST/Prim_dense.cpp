//Weight, Undirected graph

//dense graph
//complexity O(n^2)

#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll maxN = 1e3 + 1;
const ll INF = 1e9 + 1;

int n;
int g[maxN][maxN];

struct Edge {
    ll w = INF;
    int v = -1;
};

//dense graph

void prim() {
    ll total_weight = 0;
    vector <bool> used(n + 1, false);
    vector <Edge> min_e(n + 1);

    min_e[1].w = 0;

    for (int i = 1; i <= n; ++i) {
        int u = -1;
        for (int j = 1; j <= n; ++j) {
            if (!used[j] && (u == -1 || min_e[j].w < min_e[u].w)) {
                u = j;
            }
        }

        if (min_e[u].w == INF) {
            cout << "No MST exists" << endl;
            return;
        }
        used[u] = true;
        total_weight += min_e[u].w;
        if (min_e[u].v != -1) {
            //edge in minimu spanning tree
            cout << u << " " << min_e[u].v << endl;
        }

        for (int v = 1; v <= n; ++v) {
            if (g[u][v] < min_e[v].w) {
                min_e[v].w = g[u][v];
                min_e[v].v = u;
            }
        }
    }

    cout << total_weight << endl;
    return ;
}

int main() {
    return 0;
}