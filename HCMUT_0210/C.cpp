#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll maxN = 1e6 + 2;

vector <int> g[maxN];
int N,M,K;

vector <int> used;
vector <ll> d;

void bfs(int s) {
    used.resize(N + 2, 0);
    d.resize(N + 2, 0);
    used[s] = 1;

    queue <int> q;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!used[v]) {
                d[v] = d[u] + 1;
                used[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    // freopen("inp.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    cin >> N >> M >> K;
    for (int i = 0; i < K; ++i) {
        int idx;
        cin >> idx;
        g[N + 1].push_back(idx);
    }

    for (int i = 0; i < M; ++i) {
        int u,v;
        cin >> u >> v;
        g[v].push_back(u);
    }

    bfs(N + 1);
    for (int i = 1; i <= N; ++i) {
        cout << (d[i] - 1) << "\n";
    }

    return 0;
}