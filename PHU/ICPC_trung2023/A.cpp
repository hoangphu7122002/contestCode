#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll,ll>

int main() {
    // freopen("inp.txt","r",stdin);
    int n;
    cin >> n;
    vector <int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll sum = 0;
    int max_ele = -501;
    vector <pll> res;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        max_ele = max(max_ele, arr[i]);
        res.push_back({sum,max_ele});
        if (sum < 0) {
            sum = 0;
            max_ele = -501;
        }
    }

    ll max_ans = res[0].first - res[0].second;

    for (int i = 1; i < res.size(); ++i) {
        max_ans = max(max_ans, res[i].first - res[i].second);
    }
    
    cout << max_ans << endl;

    return 0;
}