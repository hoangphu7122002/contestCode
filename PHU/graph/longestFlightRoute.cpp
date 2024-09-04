#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;

vector <int> g[maxN];
bool visited[maxN];
vector <int> ans;
vector <bool> stk;

bool dfs(int v) {
    if (!visited[v]) {
        visited[v] = true;
        stk[v] = true;
        for (auto u : g[v]) {
            if (!visited[u] && dfs(u)) {
                return true;
            }
            else if (stk[u]) {
                return true;
            }
        }
    }

    stk[v] = false;
    ans.push_back(v);
    return false;
}
vector <int> trace;

int dp[maxN];

void dfs_dp(int u) {
    for (auto v : g[u]) {
        if (dp[v] < dp[u] + 1) {
            dp[v] = dp[u] + 1;
            // cout << v << ' ' << dp[v] << "\n";
            trace[v] = u;
        }
        dfs_dp(v);
    }

    return;
}

int main() {
    // freopen("inp.txt","r",stdin);
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    memset(visited,0,sizeof(visited));
    stk.resize(n + 1,0);
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) flag = dfs(i);
        if (flag == true) break;
    }
    if (flag == true) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    trace.resize(n + 1, 0);
    trace[1] = 0;
    memset(dp,-1,sizeof(dp));
    dp[1] = 0;

    reverse(ans.begin(),ans.end());
    for (auto u : ans) {
        for (auto v : g[u]) {
            if (dp[u] != -1 && dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
                trace[v] = u;
            }
        }
    }
    
    int res = n;
    vector <int> idx;
    idx.push_back(res);
    // cout << "!! " << res << "\n";
    while (trace[res] != 0) {
        res = trace[res];
        idx.push_back(res);
        // cout << "!! " << res << "\n";
        if (res == 1) flag = true;
    } 

    if (flag == true) {
        cout << idx.size() << "\n";
        reverse(idx.begin(), idx.end());
        for (auto v : idx) cout << v << " ";
    }
    else {
        cout << "IMPOSSIBLE" << "\n";
    }

    return 0;
}