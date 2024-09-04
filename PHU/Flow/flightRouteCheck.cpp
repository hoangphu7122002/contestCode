#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <bool> visited;
vector <int> g[maxN];
vector <int> g_rev[maxN];
vector <vector<int>> components;
vector <vector<int>> adj_cond;

int n,m;

void dfs(int u, vector<int> g[maxN], vector <int>& output) {
    visited[u] = true;
    for (auto v : g[u]) {
        if (!visited[v]) dfs(v,g,output);
    }
    output.push_back(u);
}

void strongComponent() {
    components.clear();
    adj_cond.clear();

    vector <int> order;
    visited.clear();
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, g, order);
        }
    }

    for (int u = 1; u <= n; ++u) {
        for (auto v : g[u]) {
            g_rev[v].push_back(u);
        }
    }

    visited.assign(n + 1,false);
    reverse(order.begin(),order.end());
    vector <int> roots(n + 1,0);

    bool flag = false;

    int num_comp = 0;
    for (auto v : order) {
        if (!visited[v]) {
            vector <int> component;
            dfs(v, g_rev, component);
            // sort(component.begin(),component.end());
            components.push_back(component);
            // int root = component.front();
            num_comp++;
            for (auto u : component) roots[u] = num_comp;
        }
        // if (components.size() >= 2) {
        //     flag = true;
        //     break;
        // }
    }
    cout << num_comp << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << roots[i] << " ";
    }

    // if (flag == false) {
    //     cout << "YES\n"; 
    // }
    // else {
    //     cout << "NO\n";
    //     cout << components[1].front() << " " << components[0].front();
    // }
    // adj_cond.assign(n, {});
    // for (int v = 0; v < n; v++)
    //     for (auto u : g[v])
    //         if (roots[v] != roots[u])
    //             adj_cond[roots[v]].push_back(roots[u]); 
}

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    strongComponent();

    return 0;
}