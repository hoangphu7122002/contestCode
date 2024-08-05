#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll s,e;
ll l,r,mid;

int main() {
    freopen("buildcol.inp","r",stdin);
    freopen("buildcol.out","w",stdout);
    ll n,M;
    cin >> n >> M;
    vector <ll> arr(n);
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    s = 0;
    e = n - 1;
    for (ll i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            break;
        }
        s = i;
    }

    for (ll i = n - 1; i >= 0; --i) {
        if (i >= 1 && arr[i] > arr[i - 1]) {
            break;
        }
        e = i;
    }

    if ((s == n - 1) || (e == 0)) {
        cout << "-1\n";
        return 0;
    }

    ll H = 0;
    ll save = -1;
    ll temp = 0;
    for (ll i = s; i <= e; ++i) {
        if (save == -1) {
            save = arr[i];
            temp = 0;
            continue;
        }
        if (arr[i] <= save) {
            temp += (save - arr[i]);
            continue;
        }
        else {
            save = arr[i];
            H += temp;
            temp = 0;
        }
    }

    if (H < M) {
        cout << "-1\n";
        return 0;
    }

    l = *min_element(arr.begin(),arr.end());
    r = *max_element(arr.begin(),arr.end());
    // cout << H << endl;
    // cout << s << " " << e << endl;
    // cout << l << " " << r << endl;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        
        temp = 0;
        for (ll i = s; i <= e; ++i) {
            if (arr[i] <= mid) {
                temp += (mid - arr[i]);
            }
        }

        if (H - temp < M) {
            r = mid;
        }
        else {
            // cout << mid << endl;
            l = mid + 1;
        }
    }

    ll res = l - 1;
    temp = 0;
    for (ll i = s; i <= e; ++i) {
        if (arr[i] <= res) {
            temp += (res - arr[i]);
        }
    }

    if (H - temp >= M) {
        cout << res << "\n";
    }
    else {
        cout << "-1\n";
    }
    
    return 0;
}