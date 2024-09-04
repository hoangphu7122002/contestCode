#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    // freopen("inp.txt","r",stdin);
    ll n,p,q;
    cin >> n >> p >> q;

    vector <ll> a(n);
    ll sum = 0;

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum >= 0) {
        bool flag = false;
        ll count = 0;
        for (ll i = 0; i < n; ++i) {
            count += 1;
            if (a[i] > 0) {
                p += a[i];
            }
            else if (a[i] == 0) {
                continue;
            }
            else {
                p += a[i];
                if (p <= q) {
                    flag = true;
                    break;
                }
                if (p < 0) p = 0;
            }
        }

        if (flag == true) {
            cout << count << endl;
        }
        else {
            cout << "-1\n";
        }
    }
    else {
        sum = abs(sum);
        ll temp = p;
        
        ll res = temp / sum;
        if (res != 0) res -= 1;
        temp = temp - (res * sum);

        ll count = 0;
        while (temp > q) {
            for (ll i = 0; i < n; ++i) {
                count += 1;
                if (a[i] > 0) {
                    temp += a[i];
                    // cout << temp << endl;
                }
                else if (a[i] == 0) {
                    continue;
                }
                else {
                    temp += a[i];
                    // cout << temp << endl;
                    if (temp <= q) {
                        cout << ((1ll * res * n) + count) << endl;
                        break;
                    }
                }
        }

    }

    }
    return 0;
}
