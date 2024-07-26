#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll,int>
#define endl "\n"
int main() {
    freopen("XDATASTRUCTURE.INP","r",stdin);
    freopen("XDATASTRUCTURE.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    stack <ll> stk;

    ll q;
    cin >> q;

    while(q--) {
        string ele;
        cin >> ele;
        // cout << ele << endl;
        if (ele == "Push") {
            // cout << "here1" << endl;
            ll val;
            cin >> val;
            if (stk.size())
                stk.push(max(stk.top(),val));
            else stk.push(val);
        }
        else if (ele == "Max") {
            // cout << "here" << endl;
            if (stk.size()) cout << stk.top() << endl;
            else cout << "-1\n";
        }
        else {
            // cout << "here2" << endl;
            if (stk.size()) stk.pop();
        }
    }

    return 0;
}