#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define maxN 101
#define MOD 2023

ll dp[maxN][maxN][maxN];

int main() {
    freopen("inp.txt","r",stdin);
    int n;
    cin >> n;

    vector <int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    sort(a.begin(),a.end());

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        dp[i][i][0] = 1; 
    }

    for (int dist = 0; dist <= n; ++dist) {
        for (int i = 1; i + dist <= n; ++i) {
            int j = i + dist;
            for (int k = 0; k <= n - 1; ++k) {
                int res = (dp[i][j][k] % MOD);
                if (res == 0) continue;
                for (int idx = j + 1; idx <= n; ++idx) {
                    if (gcd(a[j],a[idx]) == 1) {
                        (dp[i][idx][k + 1] += res) %= MOD;
                    }
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int u,v,k;
        cin >> u >> v >> k;
        int idx_u = lower_bound(a.begin(),a.end(),u) - a.begin();
        int idx_v = lower_bound(a.begin(),a.end(),v) - a.begin();
        // cout << idx_u << " " << idx_v << endl;
        cout << dp[idx_u][idx_v][k] << endl;
    }

    return 0;
}