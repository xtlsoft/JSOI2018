#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, ans = 0;

void dfs(int sum, int p, int mul) {
    if(sum > n) return;
    if(sum == n) {
        ans = max(ans, mul);
        return;
    }
    for (int i = p; i + sum <= n && i != n; i ++) {
        dfs(sum + i, i + 1, mul * i);
    }
}

int main() {

    cin >> n;

    if(n == 1) {
        cout << 0;
        return 0;
    }
    dfs(0, 1, 1);

    cout << ans;

    return 0;

}