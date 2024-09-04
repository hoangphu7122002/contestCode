#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define maxN 10001

int n, m, k ,s, t;

struct Edge {
    int v;
    ll t;
    Edge (int v, ll t) : v(v), t(t) {};
};

vector <vector<Edge>> g;
vector <vector<Edge>> add_g;

ll d[maxN][2];

struct Node {
    int u;
    ll dist_u;
    int remain;
    Node(int u, ll dist_u, int remain) : u(u), dist_u(dist_u), remain(remain) {};
};

struct cmp {
    bool operator()(const Node &a, const Node &b) const {
        return a.dist_u > b.dist_u;
    }
};

void bfs(int s){
    for (int i = 0; i < 2; ++i) d[s][i] = 0;

    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push(Node(s, 0, 1));

    while (pq.size()) {
        Node cur = pq.top();
        pq.pop();

        int u = cur.u;
        ll dist_u = cur.dist_u;
        int remain = cur.remain;

        if (d[u][remain] != dist_u) continue;
        if (u == t) {
            cout << dist_u << '\n';
            return ;
        }

        for (auto edge : g[u]) {
            int v = edge.v;
            ll t = edge.t;
            ll dist_v = dist_u + t;
            if (d[v][remain] > dist_v) {
                d[v][remain] = dist_v;
                pq.push(Node(v, dist_v, remain));
            }
        }

        for (auto edge : add_g[u]) {
            int v = edge.v;
            ll t = edge.t;
            ll dist_v = dist_u + t;
            if (remain > 0 && d[v][remain - 1] > dist_v) {
                d[v][remain - 1] = dist_v;
                pq.push(Node(v, dist_v, remain - 1));
            }
        }
    }

    cout << "-1" << endl;
}

int main() {
    // freopen("inp.txt","r",stdin);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m >> k >> s >> t;
        g.clear();
        add_g.clear();
        g.resize(n + 1);
        add_g.resize(n + 1);
        memset(d, 0x3f, sizeof(d));

        for (int i = 0; i < m; ++i) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            g[u].push_back(Edge(v, w));
        }

        for (int i = 0; i < k; ++i) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            add_g[u].push_back(Edge(v, w));
            add_g[v].push_back(Edge(u, w));
        }

        bfs(s);
    }

    return 0;
}