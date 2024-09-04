#include <bits/stdc++.h>

using namespace std;

#define maxN 100001
#define ll long long

struct vc {
    int v;
    ll c;
    vc(int _v, int _c) : v(_v), c(_c) {}
};

struct Node{
    int u;
    ll Dist_u;
};

struct cmp {
    bool operator()(const Node& a, const Node& b) const {
        return a.Dist_u > b.Dist_u;
    }
};

int n,m;
vector <vc> g[maxN];
vector <bool> used;
vector <ll> D;

// const long long INF = 2000000000000000000LL;

void dfs(int s) {
    D.resize(n + 1,-1);
    used.resize(n + 1,0);
    D[s] = 0;

    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push({s, D[s]});

    while(pq.size()) {
        Node x = pq.top();
        pq.pop();

        int u = x.u;
        if (used[u]) continue;
        used[u] = true;
        ll dist_u = x.Dist_u;

        
        for (auto e : g[u]) {
            int v = e.v;
            ll cost = e.c;
            ll dist = max(dist_u + 1,cost);
            // if (cost != 1) dist = min(dist,cost);

            if (D[v] < 0 || D[v] > dist) {
                D[v] = dist;
            
                pq.push({v, D[v]});
            }
        }
    }
}

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(vc(v, 1));
        g[v].push_back(vc(u, 1));
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        ll c;
        int u,v;
        cin >> c >> u >> v;
        g[u].push_back(vc(v, c));
        g[v].push_back(vc(u, c));
    }

    dfs(1);

    // if (D[n] == INF) cout << "-1\n";
    cout << D[n] << endl;

    return 0;
}