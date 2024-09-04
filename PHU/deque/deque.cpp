#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int N,k;
    cin >> N >> k;

    vector <ll> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    deque <int> dq;

    vector <int> minRange(N);

    for (int i = 0; i < N; ++i) {
        while (dq.size() && arr[dq.back() >= arr[i]])
            dq.pop_back();
        dq.push_back(i);
        if (dq.front() <= i - k) {
            dq.pop_front();
        }

        if (i >= k) {
            minRange[i] = arr[dq.front()];
        }
    }

    return 0;
}