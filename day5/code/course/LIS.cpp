#include <iostream>

// 定义数组p用来记录决策的结果。

using namespace std;

int main() {

    int n;
    int s[10010];
    int f[10010];

    cin >> n;

    int i, j;

    for (i = 1; i<=n; i++) cin >> s[i];

    for (i = 1; i<=n; ++i) f[i] = 1;

    for (i = 2; i<=n; i++) {
        for (j = 1; j<i; j++) {
            if(s[j] <= s[i]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }

    int ans = 0;

    for (i = 1; i <= n; i ++) {
        ans = max(ans, f[i]);
    }

    cout << ans;

    return 0;

}