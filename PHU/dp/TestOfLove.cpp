#include <bits/stdc++.h>

using namespace std;

const int maxN = 2e5 + 2;

int dp[maxN];
vector <char> a;

int main() {
    // freopen("inp.txt","r",stdin);
    int t;
    cin >> t;
    while (t--) {
        int n,m,k;
        cin >> n >> m >> k;
        a.clear();
        a.resize(n + 2);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        
        a[0] = 'L';
        a[n + 1] = 'L';
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        // cout << "here1" << endl;
        for (int i = 0; i <= n; ++i) {
            if (a[i] == 'C') {
                // dp[i][j] = 0;
                // dp[i + 1] = max(dp[i + 1],0);
                continue;
            }
            else if (a[i] == 'W') {
                dp[i + 1] = min(dp[i + 1],dp[i] + 1);
            }
            else { //a[i] = 'L'
                for (int t = 1; t <= m; ++t) {
                    if (i + t <= n + 1) {
                        dp[i + t] = min(dp[i + t],dp[i]);
                    }
                }
            }
        }
        
        if (dp[n + 1] <= k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}