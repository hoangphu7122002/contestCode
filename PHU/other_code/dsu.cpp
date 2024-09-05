// void make_set(int v) {
//     parent[v] = v;
//     sz[v] = 1; // Ban đầu tập hợp chứa v có kích cỡ là 1
// }

// void union_sets(int a, int b) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) {
//         if (sz[a] < sz[b]) swap(a, b); // Đặt biến a là gốc của cây có kích cỡ lớn hơn
//         parent[b] = a;
//         sz[a] += sz[b]; // Cập nhật kích cỡ của cây mới gộp lại
//     }
// }

// void make_set(int v) {
//     parent[v] = v;
//     rank[v] = 0; // Gốc của cây có độ cao là 0
// }

// void union_sets(int a, int b) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) {
//         if (rank[a] < rank[b]) swap(a, b); // Đặt biến a là gốc của cây có độ cao lớn hơn
//         parent[b] = a;
//         if (rank[a] == rank[b]) rank[a]++; // Nếu như hai cây có cùng một độ cao, độ cao của cây mới sau khi gộp sẽ tăng 1
//     }
// }

// struct DSU{
//     vector<int> parent, sz, sum;

//     DSU(int n) : parent(n), sz(n), sum(n) {};

//     void make_set(int v) {
//         parent[v] = v;
//         sz[v] = 1;
//         sum[v] = a[v];
//     }

//     int find_set(int v) {
//         return v == parent[v] ? v : parent[v] = find_set(parent[v]);
//     }

//     void join_sets(int a, int b) {
//         a = find_set(a);
//         b = find_set(b);
//         if (a != b) {
//             if (sz[a] < sz[b]) swap(a,b);
//             parent[b] = a;
//             sz[a] += sz[b];
//             sum[a] += sum[b];
//         }
//     }
// };