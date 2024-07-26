#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    freopen("MAXEQUATION.INP","r",stdin);
    freopen("MAXEQUATION.OUT","w",stdout);
    int m,n;
    cin >> m >> n;

    vector <ll> a(m);
    vector <ll> b(n);
    for (int i = 0; i < m; ++i){
        cin >> a[i];
        a[i] += 1;
    } 

    for (int i = 0; i < n; ++i){
        cin >> b[i];
        b[i] += 1;
    }

    ll max_ele_a = *max_element(a.begin(),a.end());
    ll min_ele_a = *min_element(a.begin(),a.end());
    ll max_ele_b = *max_element(b.begin(),b.end());
    ll min_ele_b = *min_element(b.begin(),b.end());

    ll max_final = max({max_ele_a * max_ele_b, min_ele_a * min_ele_b,max_ele_a * min_ele_b,max_ele_b*min_ele_a}) - 1;
    cout << max_final;

    return 0;
}