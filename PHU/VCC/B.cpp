#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll m,n;
    vector <ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());


    ll max_range = -1;
    for (int i = 1; i < n; ++i) {
        max_range = max(max_range, a[i] - a[i - 1]);
    }

    cout << max_range << "\n";
    return 0;
}