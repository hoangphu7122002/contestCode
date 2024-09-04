#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll dp[19][50][2][2];
string num;

ll solve(int idx, int freq, bool tight, bool start, int target1, int target2) {
    if (idx == num.length()) {
        if (!start) return 0;
        if (target2 != -1) {
            if (freq == 20) {
                return 1;
            }
            return 0;
        }
        if (freq >= 20) {
            return 1;
        }
        return 0;
    }

    if (dp[idx][freq][tight][start]!= -1) return dp[idx][freq][tight][start];

    ll ans = 0;
    int k = tight ? (num[idx] - '0') : 9;
    for (int i = 0; i <= k; ++i) {
        bool newTight = tight;
        if (i < k) newTight = 0;
        bool newStart = start || (i != 0);

        if (start && target2 != -1 && i != target1 && i != target2) continue;
        int new_k = k;
        if (newStart) {
            if (target1 == i) new_k = k + 1;
            else new_k = k - 1;
        }
        ans += solve(idx + 1, new_k, newTight, newStart, target1, target1);
    }

    return dp[idx][freq][tight][start] = ans;
}

ll countNumbers(string num) {
    ll ans = 0;
    for (int i = 0; i <= 9; ++i) {
        memset(dp, -1, sizeof(dp));
        ans += solve(0,20,0,0,i,-1);
    }

    ll duplicate = 0;
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= j; ++j) {
            memset(dp, -1, sizeof(dp));
            duplicate += solve(0,20,0,0,i,j);
        }
    }

    return ans - (duplicate / 2);
}