#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &a) {
    for (int i=0; i<a.size(); i++) cout << a[i] << " ";
    cout << endl;
}

void permute(vector<int> &a, int n) {
    while (true) {
        print(a);
        int k, l;
        for (k = n-2; k>=0; k--) if (a[k] < a[k+1]) break; // Bước 1
        if (k<0) break;                                    //
        for (l = n-1; l>k; l--) if (a[k] < a[l]) break; // Bước 2
        swap(a[k], a[l]); // Bước 3
        for (int i=k+1, j=n-1; i<j; i++, j--) swap(a[i], a[j]); // Bước 4
    }
}

void permute(vector<int> &a, int k) {
    if (k==1) return print(a);
    for (int i=0; i<k-1; i++) {
        permute(a, k-1);
        if (k%2==0) 
            swap(a[i], a[k-1]);
        else 
            swap(a[0], a[k-1]);
    }
    permute(a, k-1);
}

void permute(vector<int> &a, int n) {
    vector<int> c(0, n);
    // print(a, n);
    int i=0;
    while (i<n) {
        if (c[i] < i) {
            if (i%2 == 0) swap(a[0], a[i]);
            else swap(a[c[i]], a[i]);
            // print(a, n);
            c[i]++;
            i = 0;
        } else c[i++] = 0;
    }
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    permute(a, a.size());
    return 0;
}