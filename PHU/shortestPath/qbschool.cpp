#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pil pair<int,ll>
#define maxN 5001

int N,M;

vector <pil> g[maxN];
vector <ll> d;
vector <ll> cnt;

struct Node {
    int u;
    ll dist_u;
};

struct cmp{
    bool operator()(const Node &a, const Node &b) const {
        return a.dist_u > b.dist_u;
    }
};

void bfs(int s) {
    d.resize(N + 1,LONG_MAX);
    cnt.resize(N + 1,0);

    d[s] = 0;
    cnt[s] = 1;
    priority_queue<Node, vector<Node>, cmp> pq;

    pq.push({s,d[s]});

    while (pq.size()) {
        Node x = pq.top();
        pq.pop();

        int u = x.u;
        ll dist_u = x.dist_u;

        if (d[u] != dist_u) continue;
        for (auto e : g[u]) {
            int v = e.first;
            ll l = e.second;
            ll dist_v = dist_u + l;
            if (d[v] == dist_v) cnt[v] += cnt[u];
            else if (d[v] > dist_v) {
                cnt[v] = cnt[u];
                d[v] = dist_v;
                pq.push({v, dist_v});
            }
        }
    }
}

int main() {
    freopen("inp.txt","r",stdin);
    cin >> N >> M;
    while (M--) {
        ll k,u,v,l;
        cin >> k >> u >> v >> l;
        if (k == 1) g[u].push_back({v,l});
        else {
            g[u].push_back({v,l});
            g[v].push_back({u,l});
        }
    }
    bfs(1);
    cout << d[N] << " " << cnt[N] << endl; 

    return 0;
}