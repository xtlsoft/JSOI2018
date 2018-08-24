#include <iostream>
#include <cmath>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, d, minf;
int a[105], f[105][105], tim[105][105];

int nxtk(int k) {
    return (k * 6807 + 2831) % 201701;
}

void prew() {
    cin >> n >> d;
    a[1] = d % 100;
    for (int i = 2; i <= n; ++ i) {
        a[i] = (d = nxtk(d)) % 100;
    }
    for (int i = 1; i <= n; ++ i) {
        for (int j = i - 1; j < 100; ++ j) {
            int tmp = abs(j - a[i]);
            tmp = min(tmp, 100 - tmp);
            tim[i][j] = tmp * tmp;
        }
    }
}

int main() {

    prew();

    for (int j = 0; j < 100; ++ j) f[1][j] = tim[1][j];

    for (int i = 2; i <= n; ++ i) {
        for (int j = 0; j < 100; ++ j) {
            minf = INF;
            for (int k = 0; k < j; ++ k) {
                minf = min(minf, f[i - 1][k]);
            }
            f[i][j] = tim[i][j] + minf;
        } 
    }

    int ans = INF;
    for (int i = 0; i < n; ++ i) {
        cout << f[n - 1][i + 1] << " "; // WIP 打擂
    }

    cout << ans;

    return 0;

}