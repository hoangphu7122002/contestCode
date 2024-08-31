#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("inp.txt","r",stdin);
    int N,M;
    cin >> N >> M;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] >= M) A[i] = 1;
        else {
            A[i] = -1;
        }
    }

    vector <pair<int,int>> q;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += A[i];
        if (sum > 0) {
            q.push_back({i, sum});
            sum = 0;   
        }
    }

    if (q.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    while (sum <= 0 && q.size()) {
        auto p = *(q.end() - 1);
        q.pop_back();
        sum += p.second;
        if (sum > 0) {
            q.push_back({A.size() - 1,sum});
            break;
        }
    }

    if (sum <= 0) {
        cout << 0 << endl;
        return 0;
    }

    cout << q.size() << "\n";
    for (auto v : q) {
        cout << (v.first + 1) << " ";
    }
    
    return 0;
}