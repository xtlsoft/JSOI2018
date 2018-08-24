#include <iostream>
#include <string>

using namespace std;

string str[9];

string getTail(string a, int cnt) {
    string rslt("");
    for (int i = (a.length() - cnt); i < a.length(); ++ i) {
        rslt += a[i];
    }
    return rslt;
}

string getFront(string a, int cnt) {
    string rslt("");
    for (int i = 0; i < cnt; ++ i) {
        rslt += a[i];
    }
    return rslt;
}

string real_pj(string a, string b) {
    
    int co;
    if (a.length() > b.length()) {
        co = b.length();
    } else {
        co = a.length();
    }

    while (getTail(a, co) != getFront(b, co)) --co;
    if (co == 0) {
        return a + b;
    }else{
        return a + getTail(b, (b.length() - co));
    }

}

string pj(string a, string b) {

    string ra, rb;
    ra = real_pj(a, b);
    rb = real_pj(b, a);
    // cout << ra << " " << rb << endl;
    if (ra.length() > rb.length()) {
        return rb;
    }else{
        return ra;
    }

}

int min(int a, int b) {
    return (a < b) ? a : b;
}

const int INF = 0x3f3f3f3f;

int cntn = INF;

void dfs(int dep, int n, int c, string curr) {

    if (curr.length() >= cntn) {
        return;
    }

    if (dep == n - 1) {
        curr = pj(curr, str[c]);
        cntn = min(cntn, curr.length());
    } else {

        curr = pj(curr, str[c]);

        for (int i = (c + 1); i < n; ++ i) {
            dfs(dep + 1, n, i, curr);
        }

    }
}

int main() {

    int n;
    cin >> n;

    int r = INF;
    
    for (int i = 0; i < n; ++ i) {
        cin >> str[i];
    }

    for (int i = 0; i < n; ++ i) {
        cntn = INF;
        dfs(0, n, 0, "");
        r = min(r, cntn);
    }

    cout << r;

    return 0;

}