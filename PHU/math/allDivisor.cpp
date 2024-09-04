#include <bits/stdc++.h>

using namespace std;

vector <int> getDivisor(int n) {
    vector <int> divisors;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) {
                divisors.push_back(i);
            }
            else {
                divisors.push_back(i);
                divisors.push_back(n / i);
            }
        }
    }
    
    return vector<int> (divisors.begin(), divisors.end());
}

int main() {
    // freopen("inp.txt","r",stdin);
    int n;
    cin >> n;

    unordered_map <int,int> mp;
    for (int i = 1; i <= n; ++i) {
        int u;
        cin >> u;
        vector <int> res = getDivisor(u);
        for (auto x : res) {
            mp[x]++;
        }
    }

    // int keys = -1;
    int save_keys = -1;
    for (auto x : mp) {
        if (x.first > save_keys && x.second != 1) {
            save_keys = x.first;
        }
    }

    cout << save_keys << "\n";

    return 0;
}