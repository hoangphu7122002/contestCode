#include <bits/stdc++.h>

using namespace std;

const int maxN = 100001;

int n, m;
bool joint[maxN];
int timeDfs = 0, bridge = 0;
int low[maxN], num[maxN];
vector <int> g[maxN];

set <int> st;


void dfs(int u, int pre) {
    int child = 0; // Số lượng con trực tiếp của đỉnh u trong cây DFS
    num[u] = low[u] = ++timeDfs;
    for (int v : g[u]) {
        if (v == pre) continue;
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) {
                // cout << "!!!!\n";
                cout << "step: " << u << " " << v << "\n";
                // cout << "!!!!\n";
                st.insert(v);
                st.insert(u);
            }
            child++;
            if (u == pre) { // Nếu u là đỉnh gốc của cây DFS
                if (child > 1) {
                    joint[u] = true;
                    // cout << u << "\n";
                }
            }
            else if (low[v] >= num[u]) {
                joint[u] = true;
                // cout << u << "\n";
                cout << "!! " <<  u << " " << v << "\n";
            }
        }
        else low[u] = min(low[u], num[v]);
    }
}

int main() {
    freopen("inp.txt","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!num[i]) {
            dfs(i, i);
        }
    }

    int bridge = 0;
    for (auto ele : st) {
        if (joint[ele] == true) continue;
        bridge++;
    }
    if (bridge == 0) cout << "0\n";
    else if (bridge != 1) {
        if (bridge % 2 == 0) {
            cout << bridge / 2 << "\n";
        }
        else {
            cout << bridge / 2 + 1 << "\n";
        }
    }
    else cout << 1 << "\n";
}