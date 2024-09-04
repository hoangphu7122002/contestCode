#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define maxN 301

ll g[maxN][maxN];
int p[maxN];
int q[maxN];
ll D[maxN][maxN];

ll D_ref[maxN][maxN];

vector<int> u;
vector<int> v;
vector<int> mt;
int n,m,k;

vector<int> used;
int cur;

bool try_kuhn(int v, ll val) {
    if (used[v] == cur)
        return false;
    used[v] = cur;
    for (int u = 1; u <= k; ++u) {
        if (u != v) {    
            if (D_ref[v][u] <= val && ((mt[u] == 0) || try_kuhn(mt[u],val))) {
                mt[u] = v;
                // mt[v] = u;
                return true;
            }
        }
    }
    return false;
}

bool check(ll value) {
    mt.clear();
    used.clear();

    mt.assign(k + 1,0);
    used.assign(k + 1, false);
    for (cur = 1; cur <= k; ++cur) {
        if (used[cur] == 0) try_kuhn(cur,value);
    }

    for (int v = 1; v <= k; ++v) {
        if (mt[v] == 0) return false; 
    }
    return true;
}

int main() {
    freopen("inp.txt","r",stdin);
    cin >> n >> m >> k;

    // memset(g,0,sizeof(g));
    // memset(D,1e9,sizeof(D));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            D[i][j] = 1e9;
        }
    }
    for (int i = 0; i < m; ++i) {
        int u_,v_,w_;
        cin >> u_ >> v_ >> w_;
        // g[u_][v_] = w_;
        // g[v_][u_] = w_;
        D[u_][v_] = w_;
        D[v_][u_] = w_;
    }

    // for (int i = 1; i <= n; ++i) {
    //     D[i][i] = 0;
    // }
    int used_p[maxN];

    for (int i = 1; i <= k; ++i) {
        cin >> p[i];
        used_p[i] = p[i];
    }

    for (int i = 1; i <= k; ++i) {
        cin >> q[i];
        
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int t = 1; t <= n; ++t) {
                if (D[i][j] > D[i][t] + D[t][j]) {
                    D[i][j] = D[i][t] + D[t][j];
                }
            }
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         cout << D[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            D_ref[i][j] = 1e9;
        }
    }

    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (p[i] == q[j]) continue;
            D_ref[i][j] = D[p[i]][q[j]];
            // D_ref[j][i] = D_ref[i][j];
        }
    }    

    ll l = -1;
    ll r = 1e9;
    ll mid;
    while (r - l > 1) {
        
        mid = (r + l) / 2;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
        // cout << "=============" << endl;
        // cout << mid << " " << r << endl;
        // cout << "=============" << endl;
    }

    check(r);
    cout << r << endl;

    vector <pair<int,int>> p_;
    for (int i = 1; i <= k; ++i) {
        // cout << i << " " << mt[i] << endl;
        // cout << q[i] << " " << used_p[mt[i]] << " " << endl;
        used[mt[i]] = i;
        p_.push_back({mt[i],i});
    }
    sort(p_.begin(),p_.end());
    for (int i = 1; i <= k; ++i) {
        cout << p_[i].second << " ";
    }

    return 0;
}
