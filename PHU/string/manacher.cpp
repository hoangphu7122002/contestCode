#include <bits/stdc++.h>

using namespace std;

vector <int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector <int> p(n + 2);
    int l = 1;
    int r = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = max(0,min(r - i, p[l + r - i]));
        while (s[i + p[i]] == s[i - p[i]]) ++p[i];
        if (i + p[i] > r) {
            r = i + p[i];
            l = i - p[i];
        }
    }
    return vector <int> (begin(p) + 1, end(p) - 1);
}

vector <int> manacher (string s) {
    string t = "";
    for (auto ele : s) {
        t += string("#") + ele;
    }
    t += string("#");
    // cout << t << endl;
    auto res = manacher_odd(t);

    return vector <int> (begin(res) + 1, end(res) - 1);
}

int main() {
    freopen("inp.txt","r",stdin);
    string s;
    cin >> s;

    vector <int> d = manacher(s);
    vector <int> d_odd;
    vector <int> d_even;

    for (int i = 0; i < d.size(); ++i) {
        if (i % 2 == 0) d_even.push_back((d[i] - 1) / 2);
        else d_odd.push_back(d[i] / 2);
    }
    
    cout << d.size() << endl;
    cout << d_even.size() << " " << d_odd.size() << endl;
    // assert(d_even.size() == d_odd.size());


    int max_len = -1;
    int idx_save = -1;
    int mode = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (2 * d_odd[i] + 1 >= max_len) {
            max_len = 2 * d_odd[i] + 1;
            idx_save = i;
            mode = 1;
        }
        if (2 * d_even[i] >= max_len) {
            max_len = 2 * d_even[i];
            idx_save = i;
            mode = 0;
        }
    }

    if (mode == 0) {
        cout << s.substr(idx_save - d_even[idx_save], 2 * d_even[idx_save]) << endl;
    }
    else {
        cout << s.substr(idx_save - d_odd[idx_save], 2 * d_odd[idx_save] + 1) << endl;
    }

    return 0;
}