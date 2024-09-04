#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll xA;
ll yA;
ll xB;
ll yB;
ll A,B;
ll N,R;

vector <pair<ll,ll>> s;

ll dx[4] = {0,1,0,-1};
ll dy[4] = {-1,0,1,0};

bool checkInBorder(ll x,ll y) {
    if (x < 0 || x > A) return false;
    if (y < 0 || y > B) return false;
    return true;
}

ll PowEuclideDistance(ll x1_, ll y1_, ll x2_, ll y2_) {
    return 1ll * (x1_ - x2_) * (x1_ - x2_) + 1ll * (y1_ - y2_) * (y1_ - y2_);
}

bool isInsideCircle(ll x, ll y) {
    for (int i = 0; i < N; ++i) {
        ll sx = s[i].first;
        ll sy = s[i].second;
        ll d = PowEuclideDistance(x, y, sx, sy);
        // cout << d << " " << R * R << endl;
        if (R * R - d > 0) return true;
    }
    return false;
}

bool bfs(ll u_x,ll u_y) {
    queue<pair<ll, ll>> q;
    q.push({u_x, u_y});
    vector <vector<bool>> visited;
    visited.resize(A + 1, vector<bool>(B + 1, false));

    // cout << visited.size() << " " << visited[0].size() << endl;
    visited[u_x][u_y] = true;
    
    while(q.size()) {
        ll x = q.front().first;
        ll y = q.front().second;
        if (x == xB && y == yB) return true;
        q.pop();
        // cout << x << " " << y << "\n";
        for (ll k = 0; k < 4; k++) {
            ll new_x = x + dx[k];
            ll new_y = y + dy[k];
            // cout << "here\n";
            if (checkInBorder(new_x, new_y) &&!visited[new_x][new_y] &&!isInsideCircle(new_x, new_y)) {
                visited[new_x][new_y] = true;
                q.push({new_x, new_y});
                if (new_x == xB && new_y == yB) return true;
            }
        }
    }

    return false;
}   

int main() {
    // freopen("inp.txt","r",stdin);
    cin >> A >> B;
    cin >> R >> N;
    cin >> xA;
    cin >> yA;
    cin >> xB >> yB;

    s.resize(N);
    for (ll i = 0; i < N; i++) {
        cin >> s[i].first >> s[i].second;
    }

    bool flag = bfs(xA,yA);
    if (flag == true) {
        cout << "YES" << "\n";
    }
    else cout << "NO" << "\n";

    return 0;
}