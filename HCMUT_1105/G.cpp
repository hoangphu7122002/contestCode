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
    // freopen("inp.txt","r",stdin);
	ll n,q;
    cin >> n >> q;
    vector <ll> G(2 * n + 1ll,0);
    G[1] = ((1ll * n) * (n + 1ll)) % MOD;
    // cout << MOD << endl;

    // cout << modInverse(2,MOD) << " " << inv[2] << endl;
    ll inv2 = exp(2,MOD - 2,MOD);
    
    for (ll i = 2; i <= 2 * n; ++i) {
        G[i] = (C(2 * n + 2, i + 1) - G[i - 1] + MOD) % MOD;
        G[i] = (G[i] * inv2) % MOD;
    }

    // for (int i = 1; i <= 2 * n; ++i) {
    //     cout << G[i] << endl;
    // }
    while(q--) {
        ll x;
        cin >> x;
        // cout << "x " << x << endl;
        // if (res < 0) res += MOD;
        cout << G[x] << endl;
    }
	
    return 0;
}