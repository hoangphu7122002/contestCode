#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll,ll>
int n, m;
set <pll> s;
vector <ll> t;

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> n >> m;
    t.resize(m);
    for (int i = 0; i < n; ++i) {
        ll temp;
        cin >> temp;
        s.insert({temp,i});
    }

    for (int i = 0; i < m; ++i) cin >> t[i];

    for (int i = 0; i < m; ++i) {
        auto idx = s.lower_bound({t[i] + 1ll,0});
        if (idx == s.begin()) {
            cout << "-1" << endl;
        }
        else {
            --idx;
            cout << (*idx).first << endl;
            s.erase({idx});
        }
    }

    return 0;
}