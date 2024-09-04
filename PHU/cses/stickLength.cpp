#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n;
vector <ll> p;

int main() {
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p.begin(),p.end());

    ll res1 = 0;
    ll res2 = 0;
    for (int i = 0; i < n; ++i) {
        res1 += abs(p[i] - p[n / 2]);
        res2 += abs(p[i] - p[(n - 1) / 2]);
    }

    cout << min(res1,res2) << endl;
    return 0;
}