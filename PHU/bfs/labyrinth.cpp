#include <bits/stdc++.h>

using namespace std;

#define maxN 2001
#define ll long long
#define pii pair<int,int>

int d_y[4] = {-1,0,1,0};
int d_x[4] = {0,-1,0,1};

int n,m;
int r,c;
ll x,y;

char a[maxN][maxN];
bool used[maxN][maxN];
int dp[maxN][maxN];

void bfs(int x, int y) {
    deque <pii> dq;
    dq.push_front({x,y});
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = INT_MAX;
        }
    }

    dp[x][y] = 0;
    while (dq.size()) {
        int u_x = dq.front().first;
        int u_y = dq.front().second;
        dq.pop_front();
        if (used[u_x][u_y]) continue;
        used[u_x][u_y] = true;
        for (int k = 0; k < 4; ++k) {
            int v_x = u_x + d_x[k];
            int v_y = u_y + d_y[k];
            if (v_x < 1 || v_x > n) continue;
            if (v_y < 1 || v_y > m) continue;
            if (a[v_x][v_y] == '*') continue;
            int weight = 0;
            if (k == 0) weight = 1;
            if (dp[v_x][v_y] > dp[u_x][u_y] + weight) {
                dp[v_x][v_y] = dp[u_x][u_y] + weight;
                if (weight == 0) dq.push_front({v_x,v_y});
                else dq.push_back({v_x,v_y});
            }
        }
    }
}

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> n >> m;
    cin >> r >> c;
    cin >> x >> y;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) 
            cin >> a[i][j];

    if (a[r][c] == '*') cout << "0\n";
    else {
        bfs(r,c);
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (dp[i][j] == INT_MAX || a[i][j] == '*') continue;
                //c - L + R = j => R = j + L - c;
                int R = j + dp[i][j] - c;
                if (dp[i][j] <= x && R <= y) count += 1;
            }
        }
        cout << count << endl;
    }

    return 0;
}