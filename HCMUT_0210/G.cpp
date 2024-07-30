#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll mod;

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
            for (int j = 0; j < b.col(); ++j)
                for (int k = 0; k < a.col(); ++k){
                    c[i][j] += 1ll * a[i][k] % mod * (b[k][j] % mod) % mod;
                    c[i][j] %= mod;
                }
        return c;
    }

    Matrix pow(long long exp) {
        assert(row() == col());
        Matrix base = *this, ans = identity(row());
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }
};


int main(){
    // freopen("inp.txt","r",stdin);
    Matrix a({
        {1, 1},
        {1, 0}
    });

    int t;
    cin >> t;
    while (t--) {
        ll n,il,k;
        cin >> n >> il >> k;
        mod = k;
        Matrix tmp = a.pow(il - 1);
        vector <ll> F(k + 1,0);
        vector <ll> sum(k + 1,0);
        F[1] = (tmp[0][0] + tmp[0][1]) % k;
        F[0] = (tmp[1][0] + tmp[1][1]) % k;

        sum[0] = F[0];
        sum[1] = (sum[0] + F[1]) % mod;
        for (int i = 2; i <= k; ++i) {
            F[i] = (F[i - 1] + F[i - 2]) % mod;
            sum[i] = (sum[i - 1] + F[i]) % mod;
        }
        map <ll,int> mp;
        bool flag = false;
        for (int i = 0; i <= k; ++i) {
            if (sum[i] % k == 0) {
                cout << (i + 1) << " ";
                for (int j = 0; j <= i; ++j) {
                    cout << (j + il) << " ";
                }
                cout << "\n";
                flag = true;
                break;
            }
            if (mp.find(sum[i]) != mp.end()) {
                int j = mp[sum[i]];
                cout << (i - j) << " ";
                for (int idx = j + 1; idx <= i; ++idx) {
                    cout << (idx + il) << " ";
                }
                cout << "\n";
                flag = true;
                break;
            }
            mp[sum[i]] = i;
        }
        if (flag == false) {
            cout << "0\n";
        }
    }

    return 0;
}