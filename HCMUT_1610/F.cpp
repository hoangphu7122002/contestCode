#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    // freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector <ll> x;
    vector <ll> y;
    vector <ll> z;
    vector <ll> xy;
    vector <ll> yz;
    vector <ll> zx;
    vector <ll> xyz;

    for (int i = 0; i < n; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        x.push_back(a);
        y.push_back(b);
        z.push_back(c);
        xy.push_back(a + b);
        yz.push_back(b + c);
        zx.push_back(a + c);
        xyz.push_back(a + b + c);
    }

    ll max_x = *max_element(x.begin(),x.end());
    ll max_y = *max_element(y.begin(),y.end());
    ll max_z = *max_element(z.begin(),z.end());
    ll max_xy = *max_element(xy.begin(), xy.end());
    ll max_yz = *max_element(yz.begin(), yz.end());
    ll max_zx = *max_element(zx.begin(), zx.end());
    ll max_xyz = *max_element(xyz.begin(), xyz.end());

    ll min_last = 3e9 + 1;
    int save_idx = -1;
    for (int i = 0; i < n; ++i) {
        ll res = max({max_x - x[i],max_y - y[i],max_z - z[i],max_xy - (xy[i]),max_yz - (yz[i]),max_zx - (zx[i]),max_xyz - (xyz[i])});
        if (res < min_last) {
            min_last = res;
            save_idx = i;
        }
    }

    cout << min_last << " " << (save_idx + 1) << "\n";

    return 0;
}