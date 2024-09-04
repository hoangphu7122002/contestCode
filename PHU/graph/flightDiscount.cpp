#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 1;
int n,m;

struct Edge {
    int v;
    ll c;
};

struct save {
    ll c;
    int u;
    int remain;
};

vector <Edge> g[maxN];
ll dp[maxN][2];
vector <bool> visited;

struct cmp{
    bool operator() (save a, save b) {
        return a.c > b.c;
    }
};

void bfs(int s) {
    priority_queue <save,vector<save>,cmp> pq;
    pq.push({0, s, 1});

    // memset(dp, LONG_MAX ,sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 1; ++j) {
            dp[i][j] = 1e15 + 1;
        }
    }
    dp[s][1] = 0;
    dp[s][0] = 0;

    while (pq.size()) {
        save cur = pq.top();
        pq.pop();
        
        int u = cur.u;
        ll c = cur.c;
        int remain = cur.remain;

        if (dp[u][remain] != c) continue;

        if (u == n) return;

        for (auto edge : g[u]) {
            int v = edge.v;
        
            if (remain == 1) {
                if (dp[v][0] > c + edge.c / 2) {
                    dp[v][0] = c + edge.c / 2;
                    pq.push({dp[v][0], v, 0});
                }
            }
            if (dp[v][remain] > c + edge.c) {
                dp[v][remain] = c + edge.c;
                pq.push({dp[v][remain], v, remain});
            }
        }
    }
}

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u,v;
        ll c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
    }

    bfs(1);

    // for (int i = 1; i <= n; ++i) {
    //     cout << dp[i][0] << " " << dp[i][1] << endl;
    // }
    cout << min(dp[n][0],dp[n][1]) << "\n";

    return 0;
}