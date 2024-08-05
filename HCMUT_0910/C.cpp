#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MaxN = 5001;
ll w[MaxN];

int main() {
    // freopen("inp.txt","r",stdin);
    ll T;
    cin >> T;
    map <ll, int> mp;
    while(T--) {
        ll n;
        cin >> n;
        memset(w,0,sizeof(w));
        for (ll i = 1; i <= n; ++i) {
            cin >> w[i];
        }
        mp.clear();
        ll count = 0;
        for (ll b = n - 1; b >= 1; --b) {

            for (ll a = 1; a < b; ++a) {
                if (w[a] * w[b] <= 1000000) count += mp[w[a] * w[b] * 1ll];
                // cout << mp[w[a] * w[b]] << endl;
            }

            for (ll d = 1 + b; d <= n; ++d) {
                if ((w[d] % w[b]) == 0) {
                    ll res = w[d] / w[b];
                    mp[res] = mp[res] + 1;
                }
                // cout << mp[w[d] * w[b]] << endl;
            }
        }

        cout << count << "\n";
    }

    return 0;
}