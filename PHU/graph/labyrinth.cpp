#include <bits/stdc++.h>

using namespace std;

int n,m;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
char a[1001][1001];

bool check_border(int i,int j) {
    if (i < 1 || i > n) return false;
    if (j < 1 || j > m) return false;
    if (a[i][j] == '#') return false;

    return true;
}

bool flag = false;
vector <int> trace;

bool visited[1001][1001];

void bfs(int i_start, int j_start) {

    queue <pair<int,int>> q;
    q.push({i_start, j_start});
    trace.resize(n * 1001 + 1001);
    trace[i_start * 1001 + j_start] = 0;

    while (!q.empty()) {
        int i_s = q.front().first;
        int j_s = q.front().second;

        q.pop();
        if (a[i_s][j_s] == 'B') {
            flag = true;
            return;
        }
        if (visited[i_s][j_s] == true) continue;
        visited[i_s][j_s] = true;

        for (int k = 0; k < 4; ++k) {
            int new_i = i_s + dx[k];
            int new_j = j_s + dy[k];
            int idx = new_i * 1001 + new_j;
            if (!check_border(new_i,new_j)) continue;
            if (visited[new_i][new_j]) continue;

            trace[idx] = i_s * 1001 + j_s;
            q.push({new_i,new_j});
            // visited[new_i][new_j] = true;

            if (a[new_i][new_j] == 'B') {
                flag = true;
                return;
            }
        }
    }
}

int main() {
    // freopen("inp.txt","r",stdin);
    // freopen("outp.txt","w",stdout);
    cin >> n >> m;

    int i_A, j_A;
    int i_B, j_B;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                i_A = i;
                j_A = j;
            }
            if (a[i][j] == 'B') {
                i_B = i;
                j_B = j;
            }
        }
    }
    bfs(i_A,j_A);

    if (flag == false) {
        cout << "NO\n";

    }
    else {
        cout << "YES\n";
        string action = "";
        int i_check = i_B;
        int j_check = j_B;
        while (trace[i_check * 1001 + j_check] != 0) {
            int before_idx = trace[i_check * 1001 + j_check];
            int prev_i = before_idx / 1001;
            int prev_j = before_idx % 1001;
            if (prev_i - i_check == 1) action = "U" + action;
            else if (prev_i - i_check == -1) action = "D" + action;
            else if (prev_j - j_check == 1) action = "L" + action;
            else if (prev_j - j_check == -1) action = "R" + action;
            
            i_check = prev_i;
            j_check = prev_j;
        }
        // reverse(action.begin(), action.end());
        cout << action.size() << "\n";
        cout << action << "\n";
    }

    return 0;
}