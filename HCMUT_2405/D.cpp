#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll n,m;

ll find_max_area(vector <ll> arr) {
    vector <ll> L(n + 2,0);
    vector <ll> R(n + 2,0);
    

    deque <ll> dq;
    for (ll i = 0; i <= n + 1; ++i) {
        while (dq.size() && arr[dq.front()] >= arr[i]) {
            dq.pop_front();
        }
        if (dq.size()) L[i] = dq.front() + 1;
        else L[i] = i;
        dq.push_front(i);
    }

    dq.clear();
    for (ll i = n + 1; i >= 0; --i) {
        while (dq.size() && arr[dq.front()] >= arr[i]) {
            dq.pop_front();
        }
        if (dq.size()) R[i] = dq.front() - 1;
        else R[i] = i;
        dq.push_front(i);
        // cout << R[i] << endl;
        // cout << R[i] << endl;
    }
    // cout << "==================" << endl;

    // for (ll i = 0; i < n; ++i) {
    //     cout << i << " " << L[i] << " " << R[i] << endl;
    // }

    ll max_res = -1;
    for (ll i = 1; i <= n; ++i) {
        max_res = max(max_res, 1ll * (R[i] - L[i] + 1) * arr[i]);
    }

    return max_res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("inp.txt","r",stdin);
    cin >> m >> n;

    vector <ll> arr(n + 2);
    vector <ll> brr(n + 2);
    for (ll i = 1; i <= n; ++i) {
        cin >> arr[i];
        brr[i] = m - arr[i];
    }

    arr[0] = -1;
    brr[0] = -1;
    arr[n + 1] = -1;
    arr[n + 1] = -1;

    ll max_res1 = find_max_area(arr);
    ll max_res2 = find_max_area(brr);
    
    cout << max(max_res1,max_res2) << endl;

    return 0;
}