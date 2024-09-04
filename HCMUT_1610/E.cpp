#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll L, R;

bool res(ll mod) {
    if ((mod % (L + R)) < L) {
        return 0;
    }
    return 1;
}

int main() {
    // freopen("inp.txt","r",stdin);
    ll n;
    cin >> n >> L >> R;
    vector <ll> a;

    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] < L) continue;
        if (res(a[i]) == 1) {
            flag = true;
            break;
        }
    }

    if (flag == true) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }

    return 0;
}