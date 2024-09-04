#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define maxN 100
ll dp[maxN][maxN];

int main() {
    freopen("inp.txt","r",stdin);
    int N, k;
    cin >> N >> k;

    vector <ll> A(N);

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        dp[i][i] = A[i];
    }

    for (int dist = 1; dist <= N; ++dist) {
        for (int i = 1; i + dist <= N; ++i) {
            int j = i + dist;
            dp[i][j] = min(A[j], dp[i][j - 1]);
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << dp[max(1,i - k + 1)][i] << endl;
    }

    return 0;
}