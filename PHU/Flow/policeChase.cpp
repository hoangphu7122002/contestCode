#include <bits/stdc++.h>

using namespace std;

const int maxN = 501;
int g[maxN][maxN];
int g_c[maxN][maxN];
int p[maxN];

int n,m;
vector <bool> visited;

bool bfs(bool flag = false) {
    visited.clear();
    visited.resize(n + 1,0);
    queue <int> q;
    
    visited[1] = true;
    q.push(1);
    memset(p, -1, sizeof(p));
    while (q.size()) {
        int u = q.front();
        if (flag == true) cout << u << "\n";
        q.pop();
        for (int v = 1; v <= n; ++v) {
            if (g[u][v] && !visited[v]) {
                visited[v] = true;
                p[v] = u;
                if (v == n) {
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

    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
        g_c[a][b] = g_c[b][a] = 1;
    }

    while (bfs()) {
        int minflow = 1e6 + 1;
        for (int v = n, u = p[v]; u!= -1; v = u, u = p[v]) {
            minflow = min(minflow, g[u][v]);
        }
        for (int v = n, u = p[v]; u!= -1; v = u, u = p[v]) {
            g[u][v] -= minflow;
            g[v][u] += minflow;
        }
    }

    bfs(false);
    vector <pair<int,int>> res;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (g_c[i][j] && visited[i] && !visited[j]) {
                res.push_back({i,j});
            }
        }
    }

    cout << res.size() << "\n";
    for (auto &p : res) {
        cout << p.first << " " << p.second << "\n";
    }



    return 0;
}