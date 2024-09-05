// int par[N], up[N][17];
// void preprocess() {
//     for (int u = 1; u <= n; ++u) up[u][0] = par[u];
//     for (int j = 1; j < 17; ++j)
//         for (int u = 1; u <= n; ++u)
//             up[u][j] = up[up[u][j - 1]][j - 1];
// }

// int ancestor_k(int u, int k) {
//     for (int j = 0; (1 << j) <= k; ++j)
//         if (k >> j & 1) u = up[u][j];
//     return u;
// }

// int lg2[N];
// void preprocess() {
//     lg2[1] = 0;
//     for (int i = 2; i < N; ++i)
//         lg2[i] = lg2[i / 2] + 1;
// }


// void dfs(int u) {
//     for (int v : g[u]) {
//         if (v == up[u][0]) continue;
//         h[v] = h[u] + 1;

//         up[v][0] = u;
//         for (int j = 1; j < 20; ++j)
//             up[v][j] = up[up[v][j - 1]][j - 1];

//         dfs(v);
//     }
// }

// int h[N], up[N][20];
// int lca(int u, int v) {
//     if (h[u] != h[v]) {
//         if (h[u] < h[v]) swap(u, v);

//         // Tìm tổ tiên u' của u sao cho h(u') = h(v)
//         int k = h[u] - h[v];
//         for (int j = 0; (1 << j) <= k; ++j)
//             if (k >> j & 1) // Nếu bit thứ j của k là 1
//                 u = up[u][j];
//     }
//     if (u == v) return u;

//     // Tìm lca(u, v)
//     int k = __lg(h[u]);
//     for (int j = k; j >= 0; --j)
//         if (up[u][j] != up[v][j]) // Nếu tổ tiên thứ 2^j của u và v khác nhau
//             u = up[u][j], v = up[v][j];
//     return up[u][0];
// }