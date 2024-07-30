#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll N,K;
ll P;
ll Q;

vector <ll> A;
vector <ll> B;

ll gcd(ll A, ll B) {
    if (B == 0) return A;
    else return gcd(B, A % B);
}

bool check(double x, bool flag = false) {
    vector <pair<double,ll>> T(N);
    for (ll i = 0; i < N; ++i) {
        T[i] = {A[i] - x * B[i],i};
    }
    sort(T.begin(),T.end());
    reverse(T.begin(),T.end());
    double sum_ = 0;
    P = 0;
    Q = 0;
    for (ll i = 0; i < K; ++i) {
        sum_ += T[i].first;
        P += A[T[i].second];
        Q += B[T[i].second];
        if (flag == true) {
            cout << A[T[i].second] << " " << B[T[i].second] << endl;
            cout << T[i].second << endl;
        }
    }

    return sum_ >= 0;
}

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> N >> K;

    A.resize(N);
    B.resize(N);

    for (ll i = 0; i < N; ++i) cin >> A[i] >> B[i];
    // for (ll i = 0; i < N; ++i) cin >> B[i];

    double l = 0;
    double r = 1e6;
    double mid;
    for (int i = 0; i < 70; ++i) {
        mid = (r + l) / 2;
        if (check(mid) == true) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    check(mid);
    // cout << mid << endl;
    ll gcdPQ = gcd(P,Q);
    cout << (P/gcdPQ) << " " << (Q/gcdPQ) << endl;

    return 0;
}