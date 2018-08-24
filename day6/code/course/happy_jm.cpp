// 背包问题

#include <iostream>

using namespace std;

struct Good {
    int price;
    int value;
    int mul;
};

int main () {

    int n, m;
    Good goods[102];
    cin >> n >> m;

    int f[102][102] = {0}; // f[i][j] 表示前 i 个物品，背包容量为 j 时的最大总和。
 
    for (int i = 0; i < m; ++ i) {
        cin >> goods[i].price;
        cin >> goods[i].value;
        goods[i].mul = goods[i].price * goods[i].value;
    }

    for (int i = 1; i <= m; ++ i) {
        for (int j = 1; j <=n; j ++) {
            if (j >= v[i])
                f[i][j] = max(f[i-1][j], f[i-1][])
            // WIP
        }
    }

}