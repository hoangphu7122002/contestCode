#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("inp.txt","r",stdin);
    int N;
    cin >> N;
    double res = 0;
    for (int i = 1; i <= N; ++i) {
        res += (double) N / i;
    }

    cout << setprecision(6) << fixed << res << endl;
    return 0;
}