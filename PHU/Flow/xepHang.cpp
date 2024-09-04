#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll maxN = 1e6 + 1;
int ele[maxN];

int N,Q;
// int size_BIT = 0;
vector <ll> cps;
unordered_map <int,int> cnt;

int getSum(int p) {
    // cout  << "here2\n";
    int idx = p, ans = 0;
    while (idx > 0) {
        ans += ele[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void update(int u, int v) {
    // cout  << "here1\n";
    int idx = u;
    while (idx <= cps.size()) {
        ele[idx] += v;
        idx += (idx & (-idx));
    }
}

void compress(vector<ll> &a) {
    set<ll> s(a.begin(), a.end());
    vector<int> b(s.begin(), s.end());
    for (ll x: a) {
        int idx = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
        cps.push_back(idx);
        cnt[idx] += 1;
    }
}

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> N >> Q;

    vector <ll> a;
    // map <ll,ll> res;
    for (int i = 0; i < N + Q; ++i) {
        ll x;
        cin >> x;
        a.push_back(x);
    }

    compress(a);
    
    // for (int i = 0; i < N; ++i) {
    //     // cout << H[i] << " " << mp[H[i]] << "\n";
    //     update(cps[i],1);
    // } 

    for (auto &[k,v] : cnt) {
        update(k,v);
    }

    stack <int> stk;
    for (int i = Q - 1; i >= 0; --i) {
        update(cps[i + N],-1);
        stk.push(getSum(cps[i + N]) + 1);
    }
    while(stk.size()) {
        cout << stk.top() << "\n";
        stk.pop();
    }
    

    return 0;
}