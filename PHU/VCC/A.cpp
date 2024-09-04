#include <bits/stdc++.h>

using namespace std;

int main() {
    string S,X;
    cin >> X >> S;
    int i = 0;
    int count = 0;
    for (int j = 0; j < (int)S.length(); ++j) {
        if (S[j] == X[i]) i++;
        if (i == X.length()) {
            count++;
            i = 0;
        }
    }

    cout << count << "\n";
    return 0;
}