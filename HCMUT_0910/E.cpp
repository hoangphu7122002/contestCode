#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAXN = 3e6 + 1;
const ll MOD = 1e9 + 7;

ll fac[MAXN + 1];
ll inv[MAXN + 1];

ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = 1ll * res * x % m; }
		x = 1ll * x * x % m;
		n /= 2;
	}
	return res;
}

void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = 1ll * fac[i - 1] * i % MOD; }
}

void inverses() {
	inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = 1ll * inv[i] * i % MOD; }
}



ll C(int n, int r) { 
    if (r > n || r < 0) return 0;    
    return 1ll * fac[n] * inv[r] % MOD * inv[n - r] % MOD; 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	factorial();
	inverses();
    
    int t;

    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;

        cout << C(n + m - 1,n) << endl;
    }

    return 0;
}