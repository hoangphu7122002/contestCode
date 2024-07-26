#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll MOD = 1e9 + 7;

struct TrieNode {
    TrieNode* child[26];
    int cnt;
    int exist;

    TrieNode() {
        for (int i = 0; i < 26; ++i) child[i] = NULL;
        cnt = 0;
        exist = 0;
    }
};

struct Trie{
    TrieNode* root;
    int cur;
    int sum;

    Trie() : cur(0) {
        root = new TrieNode();
        sum = 0;
    }

    void add_string(string s) {
        TrieNode* p = root;
        for (auto f : s) {
            int c = f - 'a';
            if (p->child[c] == NULL) p->child[c] = new TrieNode();
            p = p->child[c];
            p->cnt++;
        }

        p->exist++;
    }

    void dfs(TrieNode* p, string temp, string res) {
        cout << temp << endl;
        if (p->exist >= 1) {
            // cnt++;
            // ans_max = max(ans_max,cnt);
            if (temp.length() == res.length()) {
                if (temp == res) this->sum += 1;
                this->sum = this->sum % MOD;
                return;
            }
        }
    
        for (int i = 0; i < 26; ++i) {
            if (p->child[i] != NULL)
                dfs(p->child[i],temp + char('a' + i),res);
        }
    }

    int dfs_root(string res) {
        this->sum = 0;
        dfs(root,"",res);

        return this->sum;
    }
    
};

int main() {
    freopen("inp.txt","r",stdin);
    Trie trie;

    int m;
    string s;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        trie.add_string(s);
    }    
    string res;
    cin >> res;
    
    cout << trie.dfs_root(res);

    return 0;
}