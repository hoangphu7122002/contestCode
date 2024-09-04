#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int maxN = 1e5 + 1;
ll MOD = 1e9 + 7;
vector <int> g[maxN];
ll dp[maxN];

bool visited[maxN];
vector <int> ans;
int n,m;

void dfs(int v) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    memset(visited,false,sizeof(visited));
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }

    reverse(ans.begin(),ans.end());

    memset(dp, 0, sizeof(dp));
    dp[1] = 1;

    for (auto u : ans) {
        for (auto v : g[u]) {
            dp[v] += dp[u];
            if (dp[v] >= MOD) dp[v] -= MOD;
        }
    }

    cout << dp[n] << "\n";

    return 0;
}