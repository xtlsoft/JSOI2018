#include <iostream>

using namespace std;

const int MAXN = 100 + 10;

int main() {

    int n;
    int f[MAXN][MAXN];
    int a[MAXN][MAXN];
    cin >> n;

    // WIP
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= i; ++ j) {
            cin >> a[i][j];
        }
    }

    for (int j = 1; j <= n; ++ j) { // ++ j 比 j ++ 快
        f[n][j] = a[n][j];
    }

    for (int i = n - 1; i > 0; -- i) {
        for (int j = 1; j <= i; ++ j) {
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];
        }
    }

    cout << f[1][1];

    return 0;

}