#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int main() {
    int L, R;
    int n;
    cin >> n >> L >> R;
    vector <ll> a;
 
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a.push_back(x);
    }
 
    ll ele = *max_element(a.begin(),a.end());
 
    ll mod = ele % (L + R);
    if (mod > L) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
    }
 
    return 0;
}