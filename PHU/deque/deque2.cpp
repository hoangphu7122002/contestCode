#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("inp.txt","r",stdin);
    int N, K;
    cin >> N >> K;
    vector<int> arr(N + 2);
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    arr[N + 1] = 0;

    vector<int> dp(N + 2);
    dp.assign(N + 2, 1e9);
    dp[0] = arr[0];
    for (int i = 1; i <= N + 1; ++i) {
        for (int j = max(0, i - K); j <= i - 1; ++j) {
            dp[i] = min(dp[i],dp[j] + arr[i]);
        }
    }

    cout << sum - dp[N + 1] << endl;
    return 0;
}