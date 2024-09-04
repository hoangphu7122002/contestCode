#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("inp.txt","r",stdin);
    int n,k;
    cin >> n >> k;

    vector <int> x(n + 1,0);
    vector <int> f(n + 1,0);
    while (k--) {
        char c,x1,x2;
        cin >> c >> x1 >> x2;
        
        if (c == 'R') {
            x[x1] += 1;
            if (x2 + 1 <= n) x[x2 + 1] -= 1;
        }
        else if (c == 'D') {
            x[x1] -= 1;
            if (x2 + 1 <= n) x[x2 + 1] += 1;
        }
        else if (c == 'H') {
            int delta = x2 - x1;
            f[x1] += 1;
            f[x2] += -delta;
            if (x2 + 1 <= n) {
                x[x2 + 1] += 1;
            }
            if (x2 + delta <= n) {
                x[x2 + delta] += -1;
                f[x2 + delta] += -delta;
            }
        }
        else {
            int delta = x2 - x1;
            f[x1] -= 1;
            f[x2] -= -delta;
            if (x2 + 1 <= n) {
                x[x2 + 1] -= 1;
            }
            if (x2 + delta <= n) {
                x[x2 + delta] -= -1;
                f[x2 + delta] -= -delta;
            }
        }
    }

    vector <int> res(n + 1,0);
    for (int i = 1; i <= n; ++i) {
        x[i] = x[i - 1] + x[i];
        res[i] = res[i - 1] + x[i] + f[i];
    }

    for (int i = 1; i <= n; ++i) {
        cout << res[i] << "\n";
    }

    return 0;
}