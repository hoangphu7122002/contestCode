#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    freopen("inp.txt","r",stdin);
    int N;
    cin >> N;
    
    vector <ll> arr(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    vector <ll> l_min(N + 1);
    vector <ll> l_max(N + 1);
    vector <ll> r_min(N + 1);
    vector <ll> r_max(N + 1);

    deque <int> dq;
    dq.clear();

    for (int k = 1; k <= N; ++k) {
        while (dq.size() && arr[dq.front()] <= arr[k]) {
            dq.pop_front();
        }
        if (dq.size()) l_max[k] = dq.front() + 1;
        else l_max[k] = k;
        dq.push_back(k); 
    }

    for (int i = 1; i <= N; ++i) {
        cout << arr[l_max[i]] << " ";
    }

    return 0;
}