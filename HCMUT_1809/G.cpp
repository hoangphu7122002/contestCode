#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 4e5 + 1;
int N,M;
int num_comp;
vector <int> g[maxN];
vector <int> g_rev[maxN];
vector <ll> A;
vector <bool> visited;

vector <ll> A_DAG;
vector <int> root;
vector <int> g_dag[maxN]; 

vector <ll> dp;

void dfs(int u, vector <int>& output) {
    visited[u] = true;
    for (auto v : g[u]) {
        if (!visited[v]) dfs(v, output);
    }
    // cout << "!==========!" << endl;
    // cout << u << endl;
    // cout << "!==========!" << endl;
    output.push_back(u);
}

void dfs_rev(int u, vector <int>& output) {
    visited[u] = true;
    for (auto v : g_rev[u]) {
        if (!visited[v]) dfs_rev(v, output);
    }
    output.push_back(u);
}

void dfs_DAG(int u, vector <int>& output) {
    visited[u] = true;
    for (auto v : g_dag[u]) {
        if (!visited[v]) dfs_DAG(v, output);
    }
    output.push_back(u);
}

void combineDAG() {
    visited.clear();
    visited.resize(N+1,0);
    vector <int> order;

    for (int i = 1; i <= N; ++i) {
        // cout << visited[i] << endl;
        // cout << "~~~~~~~~" << endl;
        if (!visited[i]) {
            // cout << "here " << i << endl;
            dfs(i, order);
        }    
    }

    visited.clear();
    visited.resize(N+1,0);
    reverse(order.begin(), order.end());
    // cout << order.size() << endl;
    // for (auto v : order) {
    //     cout << v << " ";
    // }
    // cout << endl;

    root.resize(N+1,0);
    A_DAG.resize(N+1,0);
    num_comp = 1;

    for (auto u : order) {
    
        if (!visited[u]) {
            vector <int> component;
            dfs_rev(u, component);
            // cout << "=========component============" << endl;
            // for (auto v : component) {
            //     cout << v << " ";
            // }
            // cout << endl;
            // cout << "=========component============" << endl;
            // sort(component.begin(),component.end());
            for (auto k : component) {
                root[k] = num_comp;
                A_DAG[num_comp] += A[k];
            }
            num_comp++;
        }
    }
    num_comp--;

    for (int u = 1; u <= N; ++u) {
        for (auto v : g[u]) {
            if (root[u] != root[v]) {
                g_dag[root[u]].push_back(root[v]);
            }
        }
    }
}



int main() {
    // freopen("inp.txt","r",stdin);
    cin >> N >> M;

    A.resize(N+1);

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    for (int i = 1; i <= M; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g_rev[v].push_back(u);
    }

    combineDAG();

    // for (int i = 1; i <= num_comp; ++i) {
    //     cout << A_DAG[i] << endl;
    // }

    vector <int> topo_order;
    visited.clear();
    visited.resize(num_comp+1,0);

    // cout << "!!!!!!!!!!!!!!!!" << endl;
    // cout << num_comp << endl;
    // cout << "!!!!!!!!!!!!!!!!" << endl;
    for (int i = 1; i <= num_comp; ++i) {
        if (!visited[i]) dfs_DAG(i,topo_order);
    }

    reverse(topo_order.begin(), topo_order.end());
    
    dp.resize(num_comp+1,0);
    // for (auto ele : A_DAG)
    

    // for (int i = 0; i < topo_order.size(); ++i) cout << topo_order[i] << endl;

    // for (auto v : topo_order) cout << v << endl;

    // for (int u = 1; u <= num_comp; ++u) {
    //     cout << u << " ";
    //     for (auto v : g_dag[u]) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    
    for (auto u : topo_order) {
        dp[u] = max(dp[u], A_DAG[u]);
        
        for (auto v : g_dag[u]) {
            dp[v] = max(dp[v], dp[u] + A_DAG[v]);
        }
    }
    
    // for (int i = 0; i < topo_order.size(); ++i) cout << dp[i] 
    ll max_dp = -1;
    for (auto v : topo_order) {
        max_dp = max(max_dp,dp[v]);
        // cout << dp[v] << endl;
    }

    cout << max_dp << endl;
    // for (int i = 0; i < topo_order.size(); ++i) cout << dp[i] << endl;
    
    return 0;
}