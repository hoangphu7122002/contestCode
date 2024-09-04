#include <bits/stdc++.h>
using namespace std;
int main()
{

    set<int> s;

    // Function to insert elements
    // in the set container
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(5);
    s.insert(3);

    cout << "The elements in set are: ";
    for (auto it = s.begin(); it != s.end(); it++)
        cout << *it << " ";

    return 0;
}