#include <bits/stdc++.h>

using namespace std;

vector <string> word;
vector <string> res;
vector <string> final_res;
bool flag = false;

void print_res() {
    cout << "==================" << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl << "==================" << endl;
}

void matching(string s,string temp,int len) {
    if (len == s.length()) {
        if (temp == s) {
            for (int i = 0; i < res.size(); ++i) {
                final_res.push_back(res[i]);
            }
            flag = true;
        }
        return ;
    }
    for (int i = 0; i < word.size(); ++i) {

        if ((word[i] == s.substr(len,word[i].length())) && flag == false) {
            res.push_back(word[i]);
            // print_res();
            matching(s,temp + word[i], len + word[i].length());
            res.pop_back();
            // print_res();
        }
    }
    return ;
}

int main() {
    // freopen("inp.txt","r",stdin);
    int n;
    cin >> n;
    word.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> word[i];
    }

    int q;
    cin >> q;
    while (q--) {
        res.clear();
        final_res.clear();
        flag = false;

        string head;
        cin >> head;
        matching(head, "", 0);
        if (final_res.size() != 0) {
            for (int i = 0; i < final_res.size(); ++i) {
                cout <<final_res[i] << " ";
            }
        }
        else cout << "-1";
        cout << endl;
    }

    return 0;
}