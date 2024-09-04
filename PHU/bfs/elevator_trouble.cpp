#include <bits/stdc++.h>

using namespace std;

#define maxN 1000001

int f;
int s,g;
int u,d;

vector <int> edge[maxN];
vector <bool> used;
vector <int> dp;

void bfs(int s) {
    queue <int> q;
    q.push(s);
    used[s] = true;

    while (q.size()) {
        int u = q.front();
        q.pop();

        if (u == g) return;

        for (auto v : edge[u]) {
            if (!used[v]) {
                used[v] = true;
                q.push(v);
                dp[v] = dp[u] + 1;
            }
        }
    }
}

int main() {
    cin >> f;
    cin >> s >> g;
    cin >> u >> d;

    used.resize(f,0);
    dp.resize(f,0);

    for (int i = 1; i <= f; ++i) {
        if (i + u <= f) edge[i].push_back(i + u);
        if (i - d >= 1) edge[i].push_back(i - d);
    }

    bfs(s);
    cout << dp[g] << endl;

    return 0;
}