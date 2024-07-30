#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

int n, m;
vector <pair<int, int>> g[N];

int dis[N];

int prim(int s) { // thuật toán Prim bắt đầu chạy từ đỉnh nguồn s
    int ret = 0;
    // Sử dụng priority_queue lưu khoảng cách của các đỉnh tăng dần đối với cây khung
    // Vì priority_queue.top luôn là phần tử lớn nhất, ta sẽ phải sử dụng greater<pair<int,int>>
    // để priority_queue.top là phần tử nhỏ nhất
    // các phần tử lưu trong priority queue sẽ có dạng pair<dis[u],u>
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

    // khởi tạo khoảng cách của các đỉnh là vô cùng lớn
    for (int i = 1; i <= n; i++) dis[i] = INF;

    // khởi tạo đỉnh nguồn có khoảng cách là 0 và push đỉnh này vào
    dis[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        // lấy đỉnh có khoảng cách nhỏ nhất chưa được kết nạp
        auto top = q.top(); q.pop();
        int curDis = top.first; int u = top.second;

        if (curDis != dis[u]) continue;

        // kết nạp đỉnh u vào cây khung
        ret += dis[u]; dis[u] = -INF;

        // cập nhất khoảng cách cho các đỉnh kề u
        for (auto &e : g[u]) {
            int v = e.first; int c = e.second;
            if (dis[v] > c) {
                dis[v] = c;
                q.push({ dis[v], v});
            }
        }
    }
    return ret;
}

int main() {
    return 0;
}