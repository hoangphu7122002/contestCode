#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

ll dp[501][63000];

int main() {
    // freopen("inp.txt","r",stdin);
    int n;
    cin >> n;

    // vector <int> a(n + 1);
    ll sum = 0;
    // for (int i = 1; i <= n; ++i) {
    //     a[i] = i;
    // }

    sum = (n * (n + 1)) / 2;


    if (sum % 2 != 0) {
        cout << "0\n";
    }
    else {
        sum = sum / 2;
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int x = 1; x <= sum; ++x) {
                dp[i][x] = dp[i - 1][x];
                if (x >= i) {
                    (dp[i][x] += (dp[i - 1][x - i])) %= MOD;
                }
            }        
        }
        cout << dp[n][sum] << endl;
    }

    return 0;
}