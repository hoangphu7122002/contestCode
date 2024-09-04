#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll prod(string s) {
    int i = 0;

    while (s[i] == '0') i++;
    s = s.substr(i);

    if (s.length() == 0) return -1;
    ll res = 1;
    for (auto c : s) res *= (c - '0');
    return res;
}

int main() {

    string l,r;
    cin >> l >> r;

    while (l.length() < r.length()) l = '0' + l;

    bool eq = true;
    string ans = "";
    for (int i = 0; i < r.length(); ++i) {
        string cur = r.substr(0,i);
        eq = eq && (l[i] == r[i]);
        if (i < r.length() && eq == true) continue;
        if (i < r.length()) {
            cur += char(r[i] - 1);
        }
        cur += string(r.length() - cur.length(),'9');
        if (prod(cur) > prod(ans)) ans = cur;
    }

    while (ans[0] == '0') { ans.erase(ans.begin()); }
	cout << ans << endl;

    return 0;
}