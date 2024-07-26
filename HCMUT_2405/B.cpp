#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll,ll>

int main() {
    // freopen("inp.txt","r",stdin);
    freopen("COLFLAG.INP","r",stdin);
    freopen("COLFLAG.OUT","w",stdout);
    int n,m;
    cin >> n >> m;
    unordered_map<int,ll> mp;
    
    for (int i = 0; i < n + m; ++i) {
        int u;
        cin >> u;
        mp[u] += 1;
    }

    vector <ll> p;
    for (auto [k,v] : mp) {
        p.push_back(v);
    }

    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    
    int num_color = 0;
    ll sum = 0;
    for (auto ele : p) {
        if (sum + ele < n) {
            sum += ele;
            num_color++;
        }
        else {
            num_color++;
            break;
        }
    }

    cout << num_color << "\n";

    return 0;
}