#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("inp.txt","r",stdin);
    int n;
    cin >> n;
    vector <double> k(n);
    vector <double> c(n);

    for (int i = 0; i < n; i++) cin >> k[i];
    for (int i = 0; i < n; ++i) cin >> c[i];


    double t = 0;
    double mau = 0;
    for (int i = 0; i < n; ++i) {
        t += k[i] * c[i];
        mau += 1.0/k[i];
    }

    if (t < 0) {
        cout << "-1\n";
    }
    else {
        vector <double> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = (t * 1/(k[i] * k[i])) / mau - c[i];
        }
        cout << fixed << setprecision(6) << sqrt(t * mau) << " ";
        for (auto v : res) {
            cout << fixed << setprecision(6) << v << " ";
        }
    }
    return 0;
}