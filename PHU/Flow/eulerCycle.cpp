#include <bits/stdc++.h>

using namespace std;

// struct Edge {
//     int u;
//     bool used;
//     Edge (int u) : u(u) { used = true; }
// };

const int maxN = 1e5 + 1;
set <int> g[maxN];
int n,m;

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a,b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    bool first = -1;
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        if (first == -1 && g[i].size()) {
            first = i;
        }
        if (g[i].size() % 2 == 1) {
            flag = true;
            break;
        }
    }

    if (first == -1 || flag == true) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    stack <int> st;
    st.push(first);
    vector <int> res;
    while (st.size()) {
        int u = st.top();
        // cout << u << "\n";
        if (g[u].size() == 0) {
            res.push_back(u);
            st.pop();
        }
        else {
            int v = *g[u].begin();
            g[u].erase(v);
            g[v].erase(u);
            st.push(v);
        }
    }


    if (res.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (auto x : res) {
        cout << x << " ";
    }

    return 0;
}