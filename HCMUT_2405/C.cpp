#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("inp.txt","r",stdin);
    int n;
    cin >> n;

    unordered_map <int, vector<int>> mp;

    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        mp[u].push_back(i);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x,l,r;
        cin >> x >> l >> r;
        
        if (mp[x].size() == 0) {
            cout << "0\n";
        }
        else {
            auto l_begin = lower_bound(mp[x].begin(),mp[x].end(),l);
            if (l_begin == mp[x].end()) {
                cout << "0\n";
                continue;
            }
            int idx_l = l_begin - mp[x].begin();
            
            auto r_begin = upper_bound(mp[x].begin(),mp[x].end(),r);

            int idx_r = r_begin - mp[x].begin() - 1;

            cout << (idx_r - idx_l + 1) << "\n";
        }
    }

    return 0;
}