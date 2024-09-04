#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    // freopen("inp.txt","r",stdin);
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector <ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());
    int i = 0;
    int j = n - 1;
    ll sum = 0;
    int count = 0;
    while (i <= j) {
        if (i == j) {
            count++;
            break;
        }
        sum += arr[j];
        j -= 1;
        if (sum + arr[i] <= x) {
            i += 1;
        }
        count += 1;
        sum = 0;
    }
    cout << count << endl;
}