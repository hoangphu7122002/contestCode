#include <bits/stdc++.h>

using namespace std;
#define maxN 101

int dp[maxN][maxN][maxN];

int gcd(int A, int B) {
    if (B == 0) return A;
    else return gcd(B, A % B);
}

int main() {
    // freopen("inp.txt","r",stdin);
    int n;
    cin >> n;
    vector <int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for (int dist = 1; dist < n; ++dist) {
        for (int i = 1; i + dist <= n; ++i) {
            int j = i + dist;
            for (int k = 1; k <= 100; ++k) {
                if (gcd(arr[i],arr[j]) == 1) {
                    dp[i][j][k] = max(dp[i][j - 1][k],dp[i][j - 1][k - 1] + 1);
                }
                else {
                    dp[i][j][k] = dp[i][j - 1][k];
                }
            }
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int i = lower_bound(arr.begin(),arr.end(),l) - arr.begin();
        int j = lower_bound(arr.begin(),arr.end(),r) - arr.begin();
        cout << dp[i][j][k] << endl;
    }

    return 0;
}