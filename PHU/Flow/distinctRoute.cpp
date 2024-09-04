#include <bits/stdc++.h>

using namespace std;

#define maxN 501

int g[maxN][maxN];
int c[maxN][maxN];
// int g_c[maxN][maxN];

int p[maxN];

int n,m;
vector <bool> visited;

bool bfs(bool flag) {
    visited.clear();
    visited.assign(n + 1,0);
    queue <int> q;
    
    visited[1] = true;
    q.push(1);
    memset(p, -1, sizeof(p));
    while (q.size()) {
        int u = q.front();
        // cout << u << "\n";
        q.pop();
        for (int v = 1; v <= n; ++v) {
            if (flag == true) {
                if (g[u][v] && !visited[v]) {
                    visited[v] = true;
                    p[v] = u;
                    if (v == n) {
                        return true;
                    }
                    q.push(v);
                }
            }
            else {
                if (!g[u][v] && c[u][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    p[v] = u;
                    if (v == n) {
                        return true;
                    }
                    q.push(v);
                }
            }
        }
    }

    return false;
}

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> n >> m;
    // cout << n << " " << m << "\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // g_c[u][v] = 1;
        g[u][v] = 1;
        c[u][v] = 1;
        // cout << "?\n";
    }
    // cout << "here0\n";
    while (bfs(1)) {
        int minflow = 1e6 + 1;
        for (int v = n, u = p[v]; u!= -1; v = u, u = p[v]) {
            minflow = min(minflow, g[u][v]);
        }
        for (int v = n, u = p[v]; u!= -1; v = u, u = p[v]) {
            g[u][v] -= minflow;
            g[v][u] += minflow;
        }
        // cout << "here\n";
    }
    // cout << "here1\n";
    vector <vector<int>> sol;
    
    while (bfs(0)) {
        vector <int> res;
        res.push_back(n);
        for (int v = n, u = p[v]; u != -1;v = u, u = p[v]) {
            res.push_back(u);
            g[u][v] = 1;
        }
        reverse(res.begin(), res.end());
        sol.push_back(res);
        // cout << "cut\n";
    }
    // cout << "here2\n";
    cout << sol.size() << "\n";
    for (auto &v : sol) {
        cout << v.size() << "\n";
        for (auto res : v) {
            cout << res << " ";
        }
        cout << "\n";
    }

    return 0;
}