#include <bits/stdc++.h>

using namespace std;

#define ll long long
int n,m;
const int maxN = 1e5 + 1;

vector <int> g[maxN];
vector <bool> visited;
stack <int> stk;
// bool flag = false;
// vector <int> sol;
vector <int> recStk;

bool cycle_dfs(int u) {
    if (!visited[u]) {
        stk.push(u);
        recStk[u] = true;
        visited[u] = true;
        for (auto v : g[u]) {
            if (!visited[v] && cycle_dfs(v)) {
                // flag = true;
                return true;
            }
            else if (recStk[v]) {
                // flag = true;
                stk.push(v);
                return true;
            }
        }
    }

    recStk[u] = false;
    stk.pop();
    return false;    
}

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> n >> m;
    visited.resize(n + 1,0);
    recStk.resize(n + 1,0);

    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    bool res = false;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) res = cycle_dfs(i);
        if (res == true) break;
    }

    if (res == false) {
        cout << "IMPOSSIBLE" << "\n";
    }
    else {
        vector <int> sol;

        sol.push_back(stk.top());
        int check_num = stk.top();
        stk.pop();

        while (stk.size()) {
            sol.push_back(stk.top());
            if (stk.top() == check_num) break;

            stk.pop();
        }

        cout << sol.size() << "\n";
        reverse(sol.begin(),sol.end());
        for (auto x : sol) cout << x << " ";
    }

    return 0;
}