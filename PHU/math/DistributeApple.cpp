#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e6;
const int MOD = 1e9 + 7;

ll fac[MAXN + 1];
ll inv[MAXN + 1];

ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

void inverses() {
	inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }
}

ll choose(int n, int r) { return fac[n] * inv[r] % MOD * inv[n - r] % MOD; }

int main() {
	// factorial();
	// inverses();
    // freopen("inp.txt","r",stdin);
	int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a,b,c;
        cin >> a >> b >> c;
        ll mu = exp(b,c,MOD - 1);
        ll ans = exp(a,mu,MOD);
        cout << ans << "\n";
    }
}   
