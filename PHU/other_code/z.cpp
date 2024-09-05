/*vector<int> z_algo(const string &s) {
    int n(s.size());
    vector<int> z(n);

    int l(0), r(0);
    for (int i=1; i<n; i++) {
        if (i > r) {
            l = r = i;
            while (r<n && s[r-l]==s[r]) r += 1;
            z[i] = r - l;
            r -= 1;
        } else if (z[i-l] < r-i+1) {
            z[i] = z[i-l];
        } else {
            l = i;
            while (r<n && s[r-l]==s[r]) r += 1;
            z[i] = r - l;
            r -= 1;
        }
    }

    return z;
}
*/

/*
void compress(vector<int> &a) {
    set<int> s(a.begin(), a.end());
    vector<int> b(s.begin(), s.end());
    for (int &x: a) {
        x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    }
}
*/

/*
for(int i = 2; i*i <= n; i++) {
        if (mark[i]) {
            // Xuất phát từ `i*i` vì các hợp số trước đó đều đã bị đánh dấu
            for(int j = i*i; j <= n; j+=i) {
                mark[j] = false;
            }
        }
    }
*/