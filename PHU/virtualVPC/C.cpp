#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector <ll> arr;
vector <string> c;
int n;

int main() {
    freopen("inp.txt","r",stdin);
    
    cin >> n;
    arr.resize(n,0);
    c.resize(n,0);

    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> arr[i];
        cout << c[i] << " " << arr[i] << "\n";
    }

    cout << "\n";
    int count = 0;
    vector <bool> check(n,0);
    for (int i = 0; i < n; ++i) {
        // cout << "!!: " << i << " " << check[i] << "\n";
        if (check[i] == true) continue;
        if (c[i] == "n") continue;
        // cout << i << endl;
        check[i] = true;
        ll max_n = -1;
        int save_idx = n;
        for (int j = i + 1; j < n; ++j) {
            if (check[j] == true) continue;
            if (c[j] == "n" && arr[j] >= arr[i]) {
                save_idx = j;
                break;
            } 
            if (c[j] == "n" && arr[j] > max_n) {
                max_n = arr[j];
            }
        }
        // int num_del = 0;
        cout << save_idx << " " << max_n << "\n";
        cout << "---------\n";
        vector <bool> a(n,0);
        bool flag2 = false;
        for (int j = i + 1; j < save_idx; ++j) {
            if (check[j] == true) continue;
            cout << "num: " << arr[j] << "\n";
            if (c[j] == "y" && arr[j] > max_n) {
                check[j] = true;
                cout << i << " " << j << "\n";
                // num_del = 1;
                a[j] = 1;
                flag2 = true;
            }
        }

        // vector <bool> b;
        bool flag = false;
        // count += 1;
    
        for (int j = i + 1; j < n; ++j) {
            if (c[j] == "n") break;
            check[j] = true;
            cout << i << " " << j << "\n";
            if (a[j] == 0) flag = true;
        }
        if (flag2 == false) {
            count += 1;
        } 
        else if (flag == false) {
            count += 1;
        }
        else {
            count += 2;
        }
        // cout << i << "\n";
        // for (int t = 0; t < n; ++t) {
        //     cout << check[t] << " ";
        // }
        // cout << "\n";
        // if (num_del == 0) {

        // }
        // count++;
    }

    
    cout << count << "\n";
    return 0;
}