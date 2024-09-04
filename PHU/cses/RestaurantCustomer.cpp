#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll,ll>

int n;
vector <pll> time_lst;

int main() {
    cin >> n;
    time_lst.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> time_lst[i].first >> time_lst[i].second;
    }

    std::sort(time_lst.begin(), time_lst.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });

    int ans = 1;
    for (int i = 1; i < n; ++i) {
        
    }

    return 0;
}