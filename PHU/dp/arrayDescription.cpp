#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define maxN 100001

const ll MOD = 1e9 + 7;

int n;
int m;

ll dp[maxN][101];
vector <int> x;

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> n >> m;
    x.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    if (x[0] == 0) {
        for (int i = 1; i <= m; ++i) {
            dp[0][i] = 1;
        }
    }
    else {
        dp[0][x[0]] = 1;
    }

    for (int i = 1; i < n; ++i) {
        if (x[i] == 0) {
            for (int j = 1; j <= m; ++j) {
                for (int k = -1; k <= 1; ++k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j+k]) % MOD;
                }
            }
        }
        else {
            for (int k = -1; k <= 1; ++k) {
                dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i]+k]) % MOD;
            }
        }
    }

    ll sum = 0;
    for (int i = 1; i <= m; ++i) {
        sum = (sum + dp[n - 1][i]) % MOD;
    }

    cout << sum << endl;

    return 0;
}