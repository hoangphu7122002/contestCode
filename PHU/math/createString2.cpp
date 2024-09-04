#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define MOD 1000000007
const int MAXN = 1e6 + 1;

int n;

ll fac[MAXN];
ll inv[MAXN];

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
    factorial();
    inverses(); 
    // freopen("inp.txt","r",stdin);
    string s;
    cin >> s;
    unordered_map <char, int> mp;
    int n = s.length();
    for (char c : s) {
        mp[c]++;
    }

    ll res = fac[n];
    ll deli = 1;
    for (auto [k,v]: mp) {
        deli = (deli * fac[v]) % MOD;
    }

    ll inv_deli = exp(deli, MOD - 2, MOD);
    res = (res * inv_deli) % MOD;

    cout << res << "\n";

    return 0;
}