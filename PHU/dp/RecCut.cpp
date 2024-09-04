#include <bits/stdc++.h>

using namespace std;

#define maxN 501

int dp[maxN][maxN];

int main() {
    // freopen("inp.txt","r",stdin);
    int a,b;
    cin >> a >> b;
    memset(dp,0x3f,sizeof(dp));

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) dp[i][j] = 0;
            for (int k = 1; k <= i; ++k) {
                if (j >= k) dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
            }
            for (int k = 1; k <= j; ++k) {
                if (i >= k) dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
            }
        }
    }

    cout << dp[a][b] << endl;

    return 0;
}