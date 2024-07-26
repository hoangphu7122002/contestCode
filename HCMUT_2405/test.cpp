#include <bits/stdc++.h>

using namespace std;

int main() {
    vector <int> arr{1,2,3,4,5,6,7};

    cout << (lower_bound(arr.begin(),arr.end(),8) - arr.begin()) << endl;
    return 0;
}