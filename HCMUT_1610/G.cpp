#include <bits/stdc++.h>

using namespace std;

#define maxN 101
#define ll long long
#define LL_MAX 1e18 + 100

ll k;
ll arr[maxN][maxN];
ll floyd[maxN][maxN];
int n,m;

const ll mod = 1e9 + 7;

using type = ll;

struct Matrix {
    vector <vector <type> > data;

    int row() const { return data.size(); }

    int col() const { return data[0].size(); }

    auto & operator [] (int i) { return data[i]; }

    const auto & operator[] (int i) const { return data[i]; }

    Matrix() = default;

    Matrix(int r, int c): data(r, vector <type> (c)) { }

    Matrix(const vector <vector <type> > &d): data(d) { }

    friend ostream & operator << (ostream &out, const Matrix &d) {
        for (auto x : d.data) {
            for (auto y : x) out << y << ' ';
            out << '\n';
        }
        return out;
    }

    static Matrix identity(long long n) {
        Matrix a = Matrix(n, n);
        while (n--) a[n][n] = 1;
        return a;
    }

    Matrix operator * (const Matrix &b) {
        Matrix a = *this;
        assert(a.col() == b.row());
        Matrix c(a.row(), b.col());
        for (int i = 0; i < a.row(); ++i)
            for (int j = 0; j < b.col(); ++j) {
                c[i][j] = LL_MAX;
                for (int k = 0; k < a.col(); ++k)
                    c[i][j] = min(c[i][j],a[i][k] + b[k][j]);
                }
        return c;
    }

    Matrix pow(long long exp) {
        assert(row() == col());
        Matrix base = *this;
        vector <vector<ll>> res(n,vector <ll> (n,LL_MAX));
        Matrix ans(res);
        for (int i = 0; i < n; ++i) ans[i][i] = 0; 
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }
};


int main() {
    // freopen("inp.txt","r",stdin);
    cin >> n >> m >> k;

    
    vector <vector<ll>> res(n,vector <ll> (n,LL_MAX));

    for (int i = 0; i < m; ++i) {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        res[u - 1][v - 1] = min(res[u - 1][v - 1],w);
    }

    Matrix a(res);

    Matrix tmp = a.pow(k);
    ll min_val = LL_MAX;
    for (int i = 0; i < n; ++i) {
        // cout << tmp[i][i] << "\n";
        if (min_val > tmp[i][i]) {
            min_val = tmp[i][i];
        }
    }

    // cout << LL_MAX << " ";
    if (min_val == LL_MAX) cout << "-1\n";
    else cout << min_val << "\n";

    return 0;
}