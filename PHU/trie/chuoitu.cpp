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
    int ans_max;

    Trie() : cur(0) {
        root = new TrieNode();
        ans_max = -1;
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

    void dfs(TrieNode* p, int cnt) {
        if (p->exist >= 1) {
            cnt++;
            ans_max = max(ans_max,cnt);
        }
    
        for (int i = 0; i < 26; ++i) {
            if (p->child[i] != NULL)
                dfs(p->child[i],cnt);
        }
    }

    int dfs_root() {
        dfs(root,0);

        return ans_max;
    }
    
};

int main() {
    // freopen("inp.txt","r",stdin);
    Trie trie;

    int m;
    string s;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        trie.add_string(s);
    }    

    cout << trie.dfs_root();

    return 0;
}