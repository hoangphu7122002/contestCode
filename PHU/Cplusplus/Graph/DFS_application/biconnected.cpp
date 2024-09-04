#include <bits/stdc++.h>

using namespace std;

// Danh sách kề
#define dsk vector<vector<int>>
#define N 30001

// Cấu trúc disjoint-sets
int root[N];
int find(int u) {
    if (root[u] != u) root[u] = find(root[u]);
    return root[u];
}

bool visited[N];
int active[N];
vector<int> stk;

void dfs(int u, const dsk &ke) {
    visited[u] = true;
    root[u] = u;
    stk.push_back(u);

    for (int v: ke[u]) if (visited[v]) {
        v = find(active[v]);
        while (stk.back() != v) {
            root[find(stk.back())] = v;
            stk.pop_back();
        }
    }

    for (int v: ke[u]) if (!visited[v]) {
        active[u] = v;
        dfs(v, ke);
    }

    if (stk.back() == u) stk.pop_back();
}