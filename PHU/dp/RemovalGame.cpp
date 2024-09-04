#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define maxN 5001

ll dp[maxN][maxN];

int main() {
    // freopen("inp.txt","r",stdin);
    int n;
    cin >> n;

    ll sum = 0;
    vector <ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        dp[i][i] = x[i];
        sum += x[i];
    }

    for (int dist = 1; dist < n; ++dist) {
        for (int i = 0; i + dist < n; ++i) {
            int j = i + dist;
            dp[i][j] = max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);
        }
    }

    // cout << ((sum - dp[0][n - 1]) / 2) << endl;
    cout << ((sum + dp[0][n - 1]) / 2) << endl;
    // if (n % 2 == 0) {
    // }
    // else {
    // }

    return 0;
}