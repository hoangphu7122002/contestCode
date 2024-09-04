#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 1;
int dp[maxN];

int main() {
    for (int i = 1; i <= maxN; ++i) {
        for (int j = i; j <= maxN; j += i) {
            dp[j]++;
        }
    }

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << dp[x] << "\n";
    }
    return 0;
}