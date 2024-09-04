#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("inp.txt","r",stdin);
    map<string,int> mp;
    mp["Welcome"] = 0;
    mp["Hue"] = 0;
    mp["University"] = 0;
    mp["of"] = 0;
    mp["Sciences"] = 0;
    string s;
    while (cin >> s) {        
        if (mp.find(s) == mp.end()) continue;
        mp[s] += 1;
    }

    bool flag = false;
    for (auto [k,v] : mp) {
        if (v == 0) {
            cout << "No" << endl;
            flag = true;
            break;
        }
    }

    if (flag == false) {
        cout << "Yes" << endl;
    }

    return 0;
}