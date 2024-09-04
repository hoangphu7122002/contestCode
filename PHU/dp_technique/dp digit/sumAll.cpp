#include <bits/stdc++.h>

using namespace std;

#define ll long long

//state (idx, sum, tight)
ll dp[20][180][2];

ll solve(int idx, int sum, int tight, string s) {
    if (idx == -1) {
        return sum;
    }
    if (dp[idx][sum][tight] != -1 && tight != 1) {
        return dp[idx][sum][tight];
    }

    int k = (s[idx] - '0');
    if (tight == 0) k = 9;

    ll ret = 0;
    for (int i = 0; i <= k; ++i) {
        int newTight = 0;
        if (k == s[idx]) newTight = tight;

        ret += solve(idx - 1, sum + i, newTight, s);
    }

    if (tight != 1) dp[idx][sum][tight] = ret;

    return ret;
}

int main() {
    ll m,n;
    cin >> m >> n;
    string a,b;
    a = to_string(m - 1);
    b = to_string(n);

    memset(dp,-1,sizeof(dp));
    ll res_a = solve(a.size() - 1, 0, 1, a);
    ll res_b = solve(b.size() - 1, 0, 1, b);
    cout << res_b - res_a << endl;
}