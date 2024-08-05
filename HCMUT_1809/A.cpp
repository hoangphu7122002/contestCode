#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    freopen("WIFIPASS.INP","r",stdin);
    freopen("WIFIPASS.OUT","w",stdout);
    int Q;
    cin >> Q;
    while (Q--) {
        ll N;
        cin >> N;
        ll x = 0;
        ll y = 0;
        ll max = -1;
        ll N2 = N * N + 1;
        for (ll i = 2; i <= N; ++i) {
            ll j = N2 / i;
            if (i * j == N2) {
                if (i + j >= max) {
                    max = i + j;
                    x = i;
                    y = j;
                }
            }
        }
        if (x > y) swap(x,y);
        x = x - 1;
        y = y - 1;
        cout << to_string(x) << to_string(y) << "\n";
    }
    return 0;
}