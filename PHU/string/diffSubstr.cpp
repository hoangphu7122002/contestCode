#include <bits/stdc++.h>

using namespace std;

vector<int>z_function (string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
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
    return z;
}

int different_substr(string a) {
    string t = "";
    int n = a.length();
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        t += a[i];
        vector <int> z = z_function(t);
        int z_max = *max_element(z.begin(),z.end());    
        count += (i + 1) - z_max;
    }
    
    return count;
}

int main() {
    string s;
    
    return 0;
}