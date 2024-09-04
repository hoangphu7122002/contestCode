#include <bits/stdc++.h>

using namespace std;

#define ll long long

int max_ans = 1001;
int n;

vector <ll> arr;
vector <char> c;
vector <bool> check;

int step = 0;
void dequy(int i, int cnt) {
    if (i == n) {
        // cout << "score: " << cnt << "\n";
        max_ans = min(max_ans, cnt);
        step++;
        return;
    }
    if (check[i] == true || c[i] == 'n') {
        dequy(i + 1, cnt);
        return;
    }
    if (c[i] == 'y') check[i] = true;
    vector <int> idx;
    for (int phase = 0; phase <= 1; ++phase) {
        if (phase == 0) {
            int max_n = -1;
            int save_idx = n;

            for (int j = i + 1; j < n; ++j) {
                // cout << "!!: " << i << " " << check[i] << "\n";
                if (check[j] == true) continue;
                if (c[j] == 'n' && arr[j] >= arr[i]) {
                    save_idx = j;
                    break;
                } 
                if (c[j] == 'n' && arr[j] > max_n) {
                    max_n = arr[j];
                }
            }
            // cout << max_n << "\n";
            for (int j = i + 1; j < save_idx; ++j) {
                if (check[j] == true) continue;
                if (c[j] == 'y' && arr[j] > max_n) {
                    check[j] = true;
                    // cout << step << " " << i << " " << j << "\n";
                    idx.push_back(j);
                }
            }
        }
        else {
            for (int j = i + 1; j < n; ++j) {
                if (c[j] == 'n') break;
                check[j] = true;
                idx.push_back(j); 
            }
        }
        // cout << "step: " << i << "\n";
        dequy(i + 1, cnt + 1);
        for (auto ele : idx) {
            check[ele] = false;
        }
        idx.clear();
        // cout << idx.size() << "\n";
    }
    // check[i] = false;
    // dequy(i + 1,cnt + 1);
}

int main() {
    freopen("inp.txt","r",stdin);
    cin >> n;
    // int count = 0;
    int c_n = 1;
    c.resize(n);
    arr.resize(n);
    check.resize(n,0);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        cin >> arr[i];
        if (c[i] == 'n') {
            c_n += 1;
        }
    }
    dequy(0,0);
    // cout << max_ans << "\n";
    cout << min(max_ans,c_n) << "\n";
    return 0;
}