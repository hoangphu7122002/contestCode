#include <bits/stdc++.h>

using namespace std;

#define maxN 100000

vector <int> g[maxN];
vector <bool> used;
int component = 0;

int n,m;

void bfs(int s) {
    queue <int> q;
    q.push(s);
    used[s] = true;

    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!used[v]) {
                used[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    used.resize(n,0);

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            bfs(i);
            ++component;
        }
    }

    cout << component << endl;

    return 0;
}