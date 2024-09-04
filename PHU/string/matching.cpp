#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("inp.txt","r",stdin);
    string s;
    string t;

    cin >> s >> t;

    string new_str = t + "#" + s;
    int n = new_str.size();
    vector <int> z(n);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(z[i - l],r - i + 1);
        }

        while (i + z[i] < n && new_str[z[i]] == new_str[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    int count = 0;

    for (int i = t.length() + 1; i < n; ++i) {
        // cout << i << " " << z[i] << "\n";
        if (z[i] == t.length()) {
            count += 1;
        }
    }

    cout << count << "\n";

    return 0;
}