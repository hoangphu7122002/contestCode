#include <bits/stdc++.h>

using namespace std;

int n,m;
const int maxN = 1e4 + 1;

#define ll long long

vector <int> g[maxN];
ll a[maxN];
vector <bool> visited;
// vector <bool> inStk;
vector <int> order;
ll dp[maxN];

void dfs(int u) {
    visited[u] = true;
    for (auto v : g[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }

    order.push_back(u);
}

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> v >> u;
        g[u].push_back(v);
    }

    visited.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) dfs(i);
    }

    reverse(order.begin(), order.end());
    memset(dp,-1,sizeof(dp));
    for (auto u : order) {
        dp[u] = max(dp[u],a[u]);
        for (auto v : g[u]) {
            if (dp[v] < dp[u] + a[v]) {
                dp[v] = dp[u] + a[v];
            } 
        }
    }
    
    ll ans = *max_element(dp + 1, dp + n + 1);

    cout << ans << "\n";

    return 0;
}