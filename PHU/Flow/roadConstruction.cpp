#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 1;
int lab[maxN];
int n,m;

int find_set(int v) {
    return lab[v] < 0 ? v : lab[v] = find_set(lab[v]);
}

int max_lab = -1;

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (lab[a] > lab[b]) swap(a, b);
        lab[a] += lab[b];
        lab[b] = a;
        max_lab = max(max_lab,-lab[a]);
    }
}

int main() {
    // freopen("inp.txt", "r", stdin);
    memset(lab, -1, sizeof(lab));
    cin >> n >> m;
    int num_comp = n;
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        if (find_set(x) != find_set(y)) {
            union_sets(x,y);
            --num_comp;
        }
        cout << num_comp << " " << max_lab << "\n";
    }

    return 0;
}