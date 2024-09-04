#include <bits/stdc++.h>

using namespace std;

#define ll long long

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
    int ans;

    Trie() : cur(0) {
        root = new TrieNode();
        ans = 0;
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

    bool search(TrieNode* p, string s) {
        for (int i = 0; i < s.length(); ++i) {
            int c = s[i] - 'a';
            if (p->child[c] == NULL)
                return false;
            p = p->child[c];  
        }

        return p->exist != 0;
    }

    void dfs(TrieNode* p){}
};

int main() {
    // freopen("inp.txt","r",stdin);
    Trie trie;
    string res;
    cin >> res;
    int m;
    string s;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        trie.add_string(s);
    }    


    return 0;
}