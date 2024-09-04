#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll,ll>

int main() {
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector <pll> a(n + 1);

    int i = 1;
    int j = n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(),a.end());

    while (i < j) {
        ll sum = a[i].first + a[j].first;
        if (sum == x) {
            break;
        }
        else if (sum > x) {
            j--;
        }
        else {
            i++;
        }
    } 

    if (i >= j) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << a[i].second << " " << a[j].second << endl;
    }
    return 0;
}