#include <bits/stdc++.h>

using namespace std;

#define maxN 10001
#define ll long long

int N,K,R;

struct Edge {
    int v;
    ll l;
    ll t;
    Edge (int v, ll l, ll t) : v(v), l(l), t(t) {};
};

vector <vector<Edge>> edge;
ll d[101][maxN]; //u, remaining cost

struct Node {
    int u;
    ll dist_u;
    ll remaining_cost;

    Node (int u, ll dist_u, ll remaining_cost) : u(u), dist_u(dist_u), remaining_cost(remaining_cost) {};  
};

struct cmp {
    bool operator()(const Node& a, const Node& b) const {
        return a.dist_u > b.dist_u;
    }
};

void bfs(int s) {
    memset(d, 0x3f, sizeof(d));
    priority_queue <Node, vector<Node>, cmp> pq;
    pq.push(Node(s, 0, K));
    d[s][K] = 0;

    while(pq.size()) {
        Node cur = pq.top();
        pq.pop();

        int u = cur.u;
        ll dist_u = cur.dist_u;
        ll remaining_cost = cur.remaining_cost;

        if (d[u][remaining_cost] != dist_u) continue;
        if (u == N) {
            cout << dist_u << endl;
            return;
        }
        for (auto ele : edge[u]) {
            int v = ele.v;
            ll l = ele.l;
            ll t = ele.t;
            ll new_remaining_cost = remaining_cost - t;
            if (new_remaining_cost < 0) continue;

            ll new_dist_u = dist_u + l;
            if (new_dist_u < d[v][new_remaining_cost]) {
                d[v][new_remaining_cost] = new_dist_u;
                pq.push({v, new_dist_u, new_remaining_cost});
            }
        }
    }
    cout << "-1" << endl;
}

int main() {
    // freopen("inp.txt","r",stdin);
    int t;
    cin >> t;
    while(t--) {
        cin >> K;
        cin >> N >> R;
        edge.clear();
        edge.resize(N + 1);
        for (int i = 1; i <= R; i++) {
            int S, D, L, T;
            cin >> S >> D >> L >> T;
            edge[S].push_back(Edge(D, L, T));
            // edge[D].push_back(Edge(S, L, T));
        }
        bfs(1);
    }
    return 0;
}