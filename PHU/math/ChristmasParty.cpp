#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll maxN = 1e6 + 1;
ll res[maxN];
ll mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    res[1] = 0;
    res[2] = 1;
    for (int i = 3; i <= n; ++i) {
        res[i] = (i - 1) * (res[i - 1] + res[i - 2]) % mod;
    }

    cout << res[n] << "\n";

    return 0;
}