#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define pll pair<ll,ll>
#define maxN 1000000001

int main() {
    freopen("inp.txt","r",stdin);
    int t;
    cin >> t;

    while(t--) {
        ll c, m, n;
        cin >> c >> m >> n;
        vector <ll> s(m);
        for (int i = 0; i < m; ++i) {
            cin >> s[i];
        }
        vector <pll> xd(n);
        for (int i = 0; i < n; ++i) {
            cin >> xd[i].first >> xd[i].second;
        }
        sort(s.begin(),s.end());
        sort(xd.begin(),xd.end());

        int j = 0;
        ll sum = 0;

        ll chua = c;
        for (int i = 0; i < n; ++i) {
            if (j < m && xd[i].first > s[j]) {
                chua = c;
                j++;
            }
            if (xd[i].second > chua) {
                continue;
            }
            sum += xd[i].second;
            chua -= xd[i].second;
        }
        cout << sum << endl;
    }
    return 0;
}