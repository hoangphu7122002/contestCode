#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n;
ll x;
vector <ll> a;

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> n;
    a.resize(n);

    ll sum = 0;
    // ll count = 0;
    map<ll,ll> mp;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (sum < 0 && sum % n != 0) mp[(sum % n) + n] += 1;
        else mp[sum % n] += 1;
    }

    ll count = 0;
    count += mp[0];

    for (auto & ele : mp) {
        ll size_c = ele.second;
        if (size_c != 0)
            count += size_c * (size_c - 1) / 2;
    }

    cout << count << endl;
    return 0;
}