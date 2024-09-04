#include <bits/stdc++.h>

using namespace std;

#define maxN 101

int dp[maxN][maxN];

int main() {
    freopen("inp.txt","r",stdin);
    int t;
    cin >> t;
    while(t--) {
        string a;
        string b;
        cin >> a >> b;
        int n = a.length();
        int m = b.length();
        a = "#" + a;
        b = "#" + b;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) dp[i][0] = 1;
        for (int i = 1; i <= m; ++i) dp[0][i] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i] == b[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
                }
            }
        }

        int lcs_length = dp[n][m] - 1;
        cout << (n + m - lcs_length) << "\n";
    }
    return 0;
}