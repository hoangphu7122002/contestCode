#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll,ll>

void print_pll(vector<pll> ele) {
    cout << "==========" << endl;
    for (auto i : ele) {
        cout << i.first << " " << i.second << endl;
    }
    cout << "==========" << endl;
}

ll num_disappear(vector<pll> ele,ll len) {
    ll num = 0;
    ll max_r = ele[0].second;
    for (int i = 1; i < ele.size(); ++i) {
        if (ele[i].first > max_r) {
            num += (ele[i].first - max_r - 1);
        }
        if (max_r < ele[i].second) {
            max_r = ele[i].second;
        }
    }

    return num + ele[0].first - 1 + (len - max_r);
}

int main() {
    // freopen("inp.txt","r",stdin );
    ll N;
    ll X,Y;
    cin >> N >> X >> Y;
    vector <pll> x_list;
    vector <pll> y_list;
    
    for (int i = 0; i < N; ++i) {
        ll x, y, w;
        cin >> x >> y >> w;
        // cout << max(x - w,1ll * 1) << endl;
        x_list.push_back({max(x - w,1ll * 1),min(x + w,X)});
        y_list.push_back({max(y - w,1ll * 1),min(y + w,Y)});
    }

    // print_pll(x_list);
    // print_pll(y_list);

    sort(x_list.begin(),x_list.end());
    sort(y_list.begin(),y_list.end());

    ll num_x = num_disappear(x_list,X);
    ll num_y = num_disappear(y_list,Y);
    // cout << num_x << " " << num_y << endl;
    cout << (X * Y - num_x * num_y) << endl;

    return 0;
}