#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    // freopen("inp.txt","r",stdin);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector <ll> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        bool flag = false;
        int sum = 1;
        for (int i = 0; i < n; ++i) {
            if (sum < arr[i]) {
                flag = true;
                break;
            }
            sum += arr[i];
        }
        if (flag == false) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}