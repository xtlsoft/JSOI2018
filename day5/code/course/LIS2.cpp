#include <iostream>

// 定义数组p用来记录决策的结果。

using namespace std;

void dgOutput(int k, int* p, int* s) {
    if (p[k] > 0) {
        dgOutput(p[k], p, s);
    }

    cout << s[k] << " ";
}

int main() {

    int n;
    int s[10010];
    int f[10010];
    int p[10010];

    cin >> n;

    int i, j;

    for (i = 1; i<=n; i++) cin >> s[i];

    for (i = 1; i<=n; ++i) f[i] = 1;

    for (i = 2; i<=n; i++) {
        for (j = 1; j<i; j++) {
            if(s[j] <= s[i]) {
                if (f[i] <= f[j]) {
                    f[i] = f[j] + 1;
                    p[i] = j;
                }
            }
        }
    }

    int ans = 0;
    int k = 0;

    for (i = 1; i <= n; i ++) {
        if (f[i] > ans) {
            ans = f[i];
            k = i;
        }
    }

    cout << ans << endl; // 输出长度

    dgOutput(k, p, s);

    return 0;

}