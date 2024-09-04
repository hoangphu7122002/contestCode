#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const long long INF_LL = 1e18;
const int INF = 1e9 + 100;
const long double EPS = 1e-6;
const int BLOCK = 550;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

void open_file() {
    #ifdef THEMIS
        freopen(INP ".txt","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

const int maxN = 1e6 + 100;
const int MOD = 1e9 + 7;

long long gcd(long long x, long long y) {
    return y == 0 ? abs(x) : gcd(y, x % y);
}

long long lcm(long long x, long long y) {
    return x / gcd(x, y) * y;
}
struct Fraction{
    long long x, y;
    Fraction(){};
    Fraction(long long _x, long long _y) : x(_x), y(_y) {
        normal();
    };
    void normal() {
        long long GCD = gcd(x, y);
        x /= GCD;
        y /= GCD;
        if (y < 0) {
            x *= -1;
            y *= -1;
        }
    }
    Fraction operator+ (const Fraction& A){
        long long mau = lcm(y, A.y);
        long long tu = x * (mau / y) + (mau / A.y) * A.x;
        return Fraction(tu, mau);
    }
    Fraction operator- (const Fraction& A){
        long long mau = lcm(y, A.y);
        long long tu = x * (mau / y) - (mau / A.y) * A.x;
        return Fraction(tu, mau);
    }
};

bool is_val(char s){
    return '0' <= s && s <= '9';
}

void sol() {
    string s;
    while (getline(cin, s)){
        s = '(' + s + ')';
        int i = 0;
        auto fn = [&](int &i){
            long long tu = 0;
            while (i < (int)s.size() && is_val(s[i]))
                tu = tu * 10 + (s[i++] - '0');
            return tu;
        };

        stack<Fraction> st;
        stack<char> op;
        while (i < (int)s.size()){
            if (is_val(s[i])) {
                long long tu = fn(i);
                i++;
                long long mau = fn(i);
                st.push(Fraction(tu, mau));
            }
            else{
                if (s[i] == ')'){
                    cerr << "ok" << '\n';
                    vector<Fraction> process;
                    vector<char> tmp_op;
                    while (op.top() != '(') {
                        Fraction F = st.top(); process.push_back(F);
                        tmp_op.push_back(op.top());
                        st.pop(); op.pop();
                    }
                    process.push_back(st.top()); st.pop();
                    tmp_op.push_back('+'); op.pop();
                    Fraction res(0, 1);
                    assert((int)process.size() == (int)tmp_op.size());
                    for (int i = 0; i < (int)process.size(); i++) {
                        if (tmp_op[i] == '+') res = res + process[i];
                        else res = res - process[i];
                    }
                    st.push(res);
                }
                else {
                    op.push(s[i]);
                }
                i++;
            }
        }
        cout << st.top().x << "/" << st.top().y << '\n';
    }
}

void solve() {
    int T = 1;
    //cin >> T;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        cerr << "Processing test = " << TestCase << '\n';
        //cout << "Case #" << TestCase << ": ";
        sol();
        //if (T) cout << '\n';
    }
}

int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
    return 0;
}