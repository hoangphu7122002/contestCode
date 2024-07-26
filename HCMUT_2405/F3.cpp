#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll maxN = 1e5 + 1;

const ll MOD = 1e9 + 7;
const ll num = 4000 * 100;

int Trie[num][26];
int End[num];
int SL = 0;
ll dp[maxN];

void add(string s) {
    int root = 0;
    for (int i = 0; i < s.size(); i++) {
        int digit = s[i] - 'a';
        if (Trie[root][digit] == 0) {
            Trie[root][digit] = ++SL;
        }
        root = Trie[root][digit];
    }
    End[root] = 1;
}

int main() {
    // freopen("inp.txt","r",stdin);
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        reverse(s.begin(),s.end());
        add(s);
    }

    string res;
    cin >> res;
    res = res;
    dp[0] = 1;
    for (int i = 1; i <= res.size(); ++i) {
        int root = 0;
        int j = i;
        while (j > 0 && Trie[root][res[j - 1] - 'a'] != 0) {
            int digit = res[j - 1] - 'a';

            root = Trie[root][digit];
            if (End[root]) {
                dp[i] = (dp[i] + dp[j - 1]) % MOD;
            }
            j--;
        }
    }
    cout << dp[res.size()] << endl;
    // cout << dp[res.size() - 1] << endl;


    return 0;
}