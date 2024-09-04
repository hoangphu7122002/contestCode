#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <int> g[maxN];
int n,m;
vector <bool> visited;
vector <int> tin,low;
int time_r = 0;
int bridge = 0;
void dfs(int u, int parent = -1) {
    visited[u] = true;
    // stk.push(u);
    tin[u] = low[u] = time_r++;
    bool parent_skip = false;
    for (auto v : g[u]) {
        if (v == parent && !parent_skip) {
            parent_skip = true;
            continue;
        }
        if (visited[v]) {
            low[u] = min(low[u],tin[v]);
        }
        else {
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if (low[v] > tin[u]) {
                cout << u << " " << v << "\n";
                bridge++;
            }
        }
    }
}

int main() {
    freopen("inp.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    visited.resize(n + 1,0);
    tin.resize(n + 1,-1);
    low.resize(n + 1,-1);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 0) {
            count += 1;
        }
    }
    if (count != 0) {
        if (count == 1) bridge += 2;
        else {
            bridge += (count + 1);
        }
    }
    
    cout << (bridge - 1) << "\n";
    return 0;
}