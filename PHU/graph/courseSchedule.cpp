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

    reverse(ans.begin(), ans.end());

    for (auto v : ans) {
        cout << v << " ";
    }

    return 0;
}