#include <bits/stdc++.h>
 
using namespace std;
 
const int maxN = 2e5 + 1;
 
vector <int> g[maxN];
vector <bool> used;
vector <bool> stk;
 
int m,n;
vector <string> U,V;
vector <char> Type;

//find cycle
bool dfs(int u) { 
    if (used[u] == false) {
        used[u] = true;
        stk[u] = true;
        for (auto v : g[u]) {
            if (!used[v] && dfs(v)) {
                // stk.clear();
                return true;
            }
            if (stk[v]) {
                // stk.clear();
                return true;
            }
        }
    }
    stk[u] = false;
    return false;
}
 
void readInput() {
    // cout << "here" << endl;
    cin >> m;
    vector <string> names;
    U.resize(m);
    V.resize(m);
    Type.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> U[i] >> Type[i] >> V[i];
        names.push_back(U[i]);
        names.push_back(V[i]);
    }
    sort(names.begin(), names.end());
    names.resize(unique(names.begin(), names.end()) - names.begin());
    //or names.erase(unique(names.begin(), names.end()), names.end());
    n = names.size();
    for (int i = 0; i < m; i++) {
        int u = lower_bound(names.begin(), names.end(), U[i]) - names.begin() + 1;
        int v = lower_bound(names.begin(), names.end(), V[i]) - names.begin() + 1;
        if (Type[i] == '>') g[u].push_back(v);
        if (Type[i] == '<') g[v].push_back(u);
        // cout << u << " " << v << endl;
    }
}

int main() {
    // freopen("inp.txt","r",stdin);
    readInput();
    
    used.resize(n + 1,0);
    stk.resize(n + 1,0);
 
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if (!used[i] && dfs(i)) {
            flag = false;
            break;
        }
    }
 
    if (flag == true) {
        cout << "possible";
    }
    else {
        cout << "impossible";
    }
 
    return 0;
}
