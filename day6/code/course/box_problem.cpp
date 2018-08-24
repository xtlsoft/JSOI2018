#include <iostream>

using namespace std;

int main() {

    int V, n, ths[102];
    bool f[102][102] = {false}; // 存储能不能放这个物品。

    cin >> V, n;

    for (int i = 1; i <= n; ++ i) {
        cin >> ths[i];
    }

    f[0][0] = 1;

    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j <= V; ++ j) {
            // f(3, 15) = f(2, 15) or f(2, 3)
            if (j >= v[i])
                f[i][j] = f[i-1][j] || f[i-1][j-v[i]];
            else
                f[i][j] = f[i-1][j];
        }
    }

    // WIP

    return 0;

}