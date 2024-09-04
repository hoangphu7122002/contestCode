#include <bits/stdc++.h>

using namespace std;

#define maxN 101
char arr[maxN][maxN];

int main() {
    // freopen("inp.txt","r",stdin);
    int r;
    int c;
    cin >> r >> c;
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> arr[i][j];
        }
    }

    int i_save = -1;
    int j_save = -1;
    for (int i = 0; i < r; ++i) {
        bool flag_new = false;
        for (int j = 0; j < c; ++j) {
            bool flag = false;
            for (int t = 0; t <= 2; ++t) {
                if (j + t >= c || arr[i][j + t] == 'x') {
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                i_save = i + 1;
                j_save = j + 1;
                flag_new = true;
                break;
            }
        }
        if (flag_new == true) break;
    }

    cout << i_save << " " << j_save;

    return 0;
}