#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define maxN 101
#define pii pair<int,int>

ll a[maxN][maxN];
ll res[maxN][maxN];
vector <pii> g;

int main() {
    // freopen("inp.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            a[i][j] = 1e9;
            res[i][j] = 1e9;
        }
    }

    for (int i = 0; i < m; ++i) {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
        res[u][v] = w;
        res[v][u] = w;
        g.push_back({u,v});
    }    
    if (m < n - 1) {
        cout << "-1\n";
        return 0;
    }
    for (int k = 1; k <= n; ++k) {
        for (int u = 1; u <= n; ++u) {
            for (int v = 1; v <= n; ++v) {
                if (res[u][v] > res[u][k] + res[k][v]) {
                    res[u][v] = res[u][k] + res[k][v];
                }
            }
        }
    }

    bool flag = false;
    for (auto [u,v] : g) {
        if (a[u][v] != res[u][v]) {
            flag = true;
            break;
        }
    }

    if (flag == true) {
        cout << "-1\n";
    }
    else {
        cout << (n * (n - 1) / 2) << "\n";
        for (int u = 1; u <= n; ++u) {
            for (int v = u + 1; v <= n; ++v) {
                if (res[u][v] == 1e9)
                    cout << u << " " << v << " " << (int)1e7 << "\n";
                else {
                    cout << u << " " << v << " " << res[u][v] << "\n";
                }
            }
        }
        // cout << m << "\n";
        // for (int i = 0; i < m; ++i) {
        //     int u = g[i].first;
        //     int v = g[i].second;
        //     cout << u << " " << v << " " << res[u][v] << "\n";
        // }
    }


    return 0;
}