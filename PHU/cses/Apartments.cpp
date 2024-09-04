#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    // freopen("inp.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    ll k;
    cin >> k;

    vector <ll> a(n);
    vector <ll> b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int j = 0;
    int i = 0;
    int count = 0;
    while (i < n) {
        if (j >= m) break;
        if ((a[i] - k <= b[j]) && (b[j] <= a[i] + k)) {
            // cout << i << " " << j << endl;
            count += 1;
            j += 1;
            i += 1;
            continue;
        }
        if (b[j] < a[i] - k) {
            j += 1;
            continue;
        }
        if (b[j] > a[i] + k) {
            i += 1;
            continue;
        }
    }

    cout << count << endl;

    return 0;
}