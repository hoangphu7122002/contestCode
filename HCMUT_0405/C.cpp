#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a,b,k;

ll res(ll b,ll k) {
    if (k == 0) return 1;
    // if (k == 1) return 10 % b;
    ll q = res(b, k / 2) % b;
    if (k % 2 == 0) { 
        return (q * q) % b;
    }
    return (q * ((q * 10) % b) % b);
}

int main() {
    freopen("DIGIT.INP","r",stdin);
    freopen("DIGIT.OUT","w",stdout);
    cin >> a >> b >> k;
    // a = a % b;
    // cout << a << endl;
    ll res_ = ((a * res(b,k - 1)) % b);
    res_ = (res_ * 10) / b;
    cout << res_;
    return 0;
}