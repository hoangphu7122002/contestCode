#include <bits/stdc++.h>

using namespace std;

#define ll long long
int n;
#define maxN 51

ll p[maxN];
ll c[maxN];


int main() {
    // freopen("inp.txt", "r", stdin);
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    
    int pos = 0;
    for (int i = 1; i < n; ++i) {
        if (1ll * c[pos] * p[i] < 1ll * c[i] * p[pos]) pos = i;
    }

    cout << 1 << '\n' << (pos + 1) << endl;

    return 0;
}