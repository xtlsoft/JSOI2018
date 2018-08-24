#include <iostream>

using namespace std;

const int MAXN = 10000 + 10;

int n;
int a[MAXN][MAXN];
int f[MAXN][MAXN];

int dfs(int i, int j) {

    if (f[i][j]) return (f[i][j]);
    if (i == n) return a[i][j];
    else return max(dfs(i + 1, j), dfs(i + 1, j + 1)) + a[i][j];

}

int main() {

    cin >> n;

    // WIP
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= i; ++ j) {
            cin >> a[i][j];
        }
    }

    cout << dfs(1, 1);

    return 0;

}