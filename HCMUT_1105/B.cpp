#include <bits/stdc++.h>

using namespace std;



int main() {
    freopen("NEW_GAME.INP","r",stdin);
    freopen("NEW_GAME.OUT","w",stdout);

    int T;
    cin >> T;
    while (T--) {
        int N,M;
        cin >> N >> M;
        vector <int> d(N+1);
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            d[u] += 1;
            d[v] += 1;
        }

        int count = 0;
        for (int i = 1; i <= N; ++i) {
            if (d[i] % 2 == 0) {
                count += 1;
            }
        }

        if (count % 2 == 0) cout << "Bob\n";
        else cout << "Alice\n";
        
    }    

    return 0;
}