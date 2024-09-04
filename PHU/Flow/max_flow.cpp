#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll maxN = 1e5 + 1;
vector <ll> g[maxN];
vector <vector<ll>> capacity;
vector <vector<ll>> capacity_;
ll n,m;

ll bfs(ll s,ll t, vector <ll>& parent) {
    fill(parent.begin(),parent.end(),-1);
    // for (auto ele : parent) {
    //     // << ele << " ";
    // }
    // << "\n";
    parent[s] = -2;
    queue <pair<ll,ll>> q;
    q.push({s,LONG_LONG_MAX});
    while (q.size()) {
        ll u = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for (auto v : g[u]) {
            // << u << " " << v << "\n";
            // << parent[v] << " " << capacity[u][v] << "\n";
            if (parent[v] == -1 && capacity[u][v] != 0) {
                // cout << u << " " << v << "\n";
                parent[v] = u;
                ll new_flow = min(flow, capacity[u][v]);
                if (v == t) {
                    // cout << "here\n";
                    return new_flow;
                }
                q.push({v, new_flow});

            }
        }
    }

    return 0;
}

ll maxFlow(ll s,ll t) {
    ll flow = 0;
    vector <ll> parent(n + 1,-1);
    ll new_flow;
    while (new_flow = bfs(s,t,parent)) {
        flow += new_flow;
        // << "==: " << new_flow << endl;
        ll u = t;
        while (u != s) {
            ll v = parent[u];
            capacity[v][u] -= new_flow;
            capacity[u][v] += new_flow;
            u = v; 
        }
        // cout << flow << "\n";
    }

    return flow;
}

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> n >> m;
    capacity_.assign(n + 1, vector<ll>(n + 1, 0));
    capacity.assign(n + 1, vector<ll>(n + 1, 0));

    for (int i = 0; i < m; ++i) {
        ll a,b,c;
        cin >> a >> b >> c;
        if (capacity_[a][b] == 0) {
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        capacity_[a][b] += c;
        // cout << capacity[a][b] << "\n";
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            capacity[i][j] = capacity_[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        sort(g[i].begin(),g[i].end());
        // reverse(g[i].begin(),g[i].end());
    }

    ll a = maxFlow(1,n);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            capacity[i][j] = capacity_[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        // sort(g[i].begin(),g[i].end());
        reverse(g[i].begin(),g[i].end());
    }

    ll b = maxFlow(1,n);
    cout << max(a,b) << "\n";

    return 0;
}