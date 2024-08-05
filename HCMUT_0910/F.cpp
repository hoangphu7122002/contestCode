#include <bits/stdc++.h>

using namespace std;


int N,M;

const int maxN = 4e5 + 1;
const int maxM = 4e5 + 2e5 + 2; 
vector <pair<int,int>> adj[maxN];
bool mark[maxM];
pair<int,int> ans[maxM];

int h[maxN];
void dfs(int u) {
    for (int& i = h[u]; i < adj[u].size(); ++i) {
        int v = adj[u][i].first;
        int id = adj[u][i].second;
        // cout << "================" << endl;
        // cout << "u: " << u << " v: " << v << endl;
        // cout << "================" << endl;
        if (mark[id]) continue;
        ans[id] = {u,v};
        mark[id] = true;
        dfs(v);
    }
}

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }

    vector <int> temp;
    for (int i = 1; i <= N; ++i) {
        if (adj[i].size() % 2 == 1) temp.push_back(i);
    }

    int m = M;
    for (int i = 0; i < temp.size(); i += 2) {
        int u = temp[i];
        int v = temp[i + 1];
        adj[u].push_back({v, m});
        adj[v].push_back({u, m});
        m++;
    }

    memset(mark, 0, sizeof(mark));

    for (int i = 1; i <= N; ++i) dfs(i);

    cout << (N - temp.size()) << endl;
    for (int i = 0; i < M; ++i) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    return 0;
}
