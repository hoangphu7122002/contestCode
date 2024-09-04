#include <bits/stdc++.h>

using namespace std;

int n;

int matrix[301][301];
int copy_m[301][301];

int main() {
    freopen("inp.txt","r",stdin);
    int n,m,k;
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            matrix[i][j] = INT_MAX;
            if (i == j) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        matrix[u][v] = w;
        matrix[v][u] = w;
    }


    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i][k] < INT_MAX && matrix[k][j] < INT_MAX)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                matrix[j][i] = matrix[i][j];
            }
        }
    }

    vector <int> p(k + 1);
    vector <int> q(k + 1);
    for (int i = 1; i <= k; ++i) cin >> p[i];
    for (int i = 1; i <= k; ++i) cin >> q[i];

    

    return 0;
}