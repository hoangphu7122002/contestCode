#include <bits/stdc++.h>

using namespace std;

int main() {
    vector <int> arr = {2,1,2,3,1,1,3};
    multiset <pair<int,int>> ms;

    for (int i = 0 ; i < arr.size(); ++i) {
        ms.insert({arr[i],i});
    }

    auto ptr = ms.lower_bound({1,-1});
    if (ptr == ms.end()) {
        cout << "not oke" << endl;
    }
    else {
        cout << ms.size() << endl;
        cout << "====" << endl;
        cout << (*ptr).first << " " << (*ptr).second << endl;
        ms.erase(ptr);
        cout << ms.size() << endl;
    }


    return 0;
}