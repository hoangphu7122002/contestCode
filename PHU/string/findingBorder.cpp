#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("inp.txt","r",stdin);
    string s;
    // string t;

    cin >> s;

    int n = s.length();
    vector <int> z(n);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(z[i - l],r - i + 1);
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    vector <int> res;
    for (int i = 1; i < n; ++i) {
        if (i + z[i] == n) {
            res.push_back(z[i]);
        }
    }
    reverse(res.begin(),res.end());
    for (auto ele : res) cout << ele << " ";
    return 0;
}