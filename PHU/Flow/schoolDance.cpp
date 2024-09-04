#include <bits/stdc++.h>

using namespace std;

#define maxN 1005

int g[maxN][maxN];

int p[maxN];

int n,m;
vector <bool> visited;

bool bfs() {
    visited.clear();
    visited.resize(n + m + 2,0);
    queue <int> q;
    
    visited[0] = true;
    q.push(0);
    memset(p, -1, sizeof(p));
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n + m + 1; ++v) {
            if (g[u][v] && !visited[v]) {
                visited[v] = true;
                p[v] = u;
                if (v == n + m + 1) {
                    return true;
                }
                q.push(v);
            }
        }
    }

    return false;
}

int main() {
    freopen("inp.txt","r",stdin);
    cin >> n >> m;
    int k;
    cin >> k;
    vector <pair<int,int>> save;

    for (int i = 0; i < k; ++i) {
        int u,v;
        cin >> u >> v;
        if (g[u][v + n] == 0) {
            g[u][v + n] = 1;
            save.push_back({u,v + n});
        }
    }

    for (int i = 1; i <= n; ++i) {
        g[0][i] = 1;
    }

    for (int i = 1; i <= m; ++i) {
        g[n + i][n + m + 1] = 1;
    }

    while (bfs()) {
        int minflow = 1e6 + 1;
        for (int v = n + m + 1, u = p[v]; u!= -1; v = u, u = p[v]) {
            minflow = min(minflow, g[u][v]);
        }
        for (int v = n + m + 1, u = p[v]; u!= -1; v = u, u = p[v]) {
            g[u][v] -= minflow;
            g[v][u] += minflow;
        }
    }

    vector <pair<int,int>> res;
    for (auto [u,v] : save) {
        if (g[u][v] == 0) {
            res.push_back({u, v - n});
        }
    }

    cout << res.size() << endl;
    for (auto [u,v] : res) {
        cout << u << " " << v << "\n";
    }
    return 0;
}