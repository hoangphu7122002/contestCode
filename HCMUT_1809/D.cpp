#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    // freopen("inp.txt", "r", stdin);
    int n,m;
    cin >> n >> m;

    // unordered_map <ll,ll> count;
    vector <pair<ll,int>> arr(2 * n + 1);
    vector <pair<ll,int>> brr(2 * n + 1);

    multiset <pair<ll,int>> l_mset;
    multiset <pair<ll,int>> r_mset;

    for (int i = 0; i <= 2 * n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
        brr[i].first = arr[i].first;
        brr[i].second = i;
    }

    sort(brr.begin(),brr.end());
    for (int i = 0; i <= n; ++i) l_mset.insert(brr[i]);
    for (int i = n + 1; i <= 2 * n; ++i) r_mset.insert(brr[i]);

    while (m--) {
        int i;
        ll k;

        cin >> i >> k;
        ll past_value = arr[i].first;

        if (l_mset.find({past_value,i}) != l_mset.end()) {
            l_mset.erase({past_value,i});
        }
        else {
            r_mset.erase({past_value,i});
        }

        // cout << "here1" << endl;

    
        //balance
        ll l_large = (*prev(l_mset.end())).first;

        if (k <= l_large) {
            l_mset.insert({k,i});
        }
        else {
            r_mset.insert({k,i});
        }

        if (l_mset.size() == r_mset.size() + 1) {
            // cout << "here11" << endl;
        }
        else if (l_mset.size() > r_mset.size() + 1) {
            while (l_mset.size() - r_mset.size() - 1 != 0) {
                // cout << "here2" << endl;
                auto max_value = *prev(l_mset.end());
                l_mset.erase(max_value);
                r_mset.insert(max_value);
            }
        }
        else {
            
            while (r_mset.size() + 1 - l_mset.size() != 0) {

                auto min_value = *r_mset.begin();
                r_mset.erase(min_value);
                l_mset.insert(min_value);
            }
        }
        cout << (*prev(l_mset.end())).first << endl;
        arr[i].first = k;
    }


    return 0;
}