// // 推荐贪心。逆序分配给k个人抄写。

/**
 * 合唱队形
 * 复制书稿
 * 拦截导弹
 * 方格取数
 * 饥饿的牛
 * 滑雪
 */

// #include <iostream>

// using namespace std;

// int main() {

//     cin >> n>> p;

//     for (int i = 1; i<=n; ++i) {
//         cin >> a[i];
//         d[i] = d[i-1] + a[i];
//         f[1][i] = d[1];
//     }

//     for (int i = 2; i<=p; ++i)
//         for (int j = i; i <= n; ++j) {
//             f[i][j] = INF;
//             for (int k = i - 1; k <= j - 1; ++k) {
//                 if (max(f[i - 1][k], d[j]-d[k]) < f[i][j]) {
//                     f[i][j] = max(f[i - 1][k], d[j]-d[k]);
//                     g[i][j] = k;
//                 }
//             }
//         }

//     int now = n;

//     // for () // 输出

// }