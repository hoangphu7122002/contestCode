#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+5;
const int INF = 1e9+5;

vector<pair<int, int>> g[MAXN*MAXN*2];
int d[MAXN*MAXN*2], vis[MAXN*MAXN*2];

int encode(int type, int i, int j) {    // mã hóa ô (i, j) của đồ thị type thành 1 số
    return (type-1)*MAXN*MAXN + i*MAXN + j;
}

void add_edge(int a, int b, int w) {
    g[a].push_back({b, w});
    g[b].push_back({a, w});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char x;
            cin >> x;
            d[encode(1, i, j)] = INF;
            d[encode(2, i, j)] = INF;
            if(x == '#')add_edge(encode(1, i, j), encode(2, i, j), 1);
            if(j > 1)add_edge(encode(1, i, j-1), encode(1, i, j), 0);
            if(i > 1)add_edge(encode(2, i-1, j), encode(2, i, j), 0);
        }
    }

    deque<int> dq;
    d[encode(1, 1, 1)] = 0;
    dq.push_front(encode(1, 1, 1));
    while(!dq.empty()){
        auto u = dq.front();
        if(u == encode(1, n, m)){
            cout << d[u];
            return 0;
        }
        dq.pop_front();
        if(vis[u])continue;;
        vis[u] = 1;
        for(pair<int, int> v: g[u]){
            if(d[v.first] > d[u] + v.second){
                d[v.first] = d[u] + v.second;
                if(!v.second)dq.push_front(v.first);
                else dq.push_back(v.first);
            }
        }
    }
    cout << "-1";
}