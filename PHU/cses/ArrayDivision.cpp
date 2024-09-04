#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n,k;
vector <ll> x;

bool check(ll value) {
    ll sum = 0;
    ll k_check = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] > value) return false;
        sum += x[i];
        if (sum > value) {
            sum = x[i];
            k_check++;
        }
    }
    k_check++;
    return k_check <= k;
}

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> n >> k;
    x.resize(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        sum += x[i];
    }

    ll lo = 0;
    ll hi = sum;

    ll ans = 0;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid) == true) {
            hi = mid - 1;
            ans = mid;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}