#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int toInt(string a) {

    int rslt = 0;
    sscanf(a.c_str(), "%d", &rslt);

    return rslt;

}

int n, k, maxn = 0;
int f[102][102];

string toString(int a) {

    char b[32];
    sprintf(b, "%d", a);

    return string(b);

}

int calc(vector<int> j) {

    int rslt = 1;

    for (int i = 0; i < j.size(); ++ i) {
        // cout << j[i] << " ";
        rslt *= j[i];
    }

    // cout << rslt << endl;

    return rslt;

}

void dfs(string str, int ni, vector<int> j, int last) {

    if (ni == k + 1) maxn = max(maxn, calc(j));
    else if (last == str.length()) return;
    else for (int i = last; i <= str.length(); ++ i) {
        string ns = str.substr((last), (i - last));
        if (ns == "") continue;
        int nn = toInt(ns);
        j.push_back(nn);
        dfs(str, ni + 1, j, i);
        j.pop_back();
    }

}

int main() {
    
    cin >> n >> k;

    string str;
    cin >> str;

    vector<int> j;

    dfs(str, 0, j, 0);

    cout << maxn;

    return 0;

}