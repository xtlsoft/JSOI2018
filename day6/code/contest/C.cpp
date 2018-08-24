#include <cstdio>

using namespace std;

int m, n, mp[102][102];
int maxn = 0;
int f[102][102];

int gmax(int a, int b) {
    return (a > b) ? a : b;
}

void dfs(int i, int machineNum, int dep) {

    if (dep < f[i][machineNum]) return;
    f[i][machineNum] = dep;

    if (machineNum == 0)
        maxn = gmax(maxn, dep);
    else if (i == n) return;
    else for (int j = 0; j <= machineNum; j ++) {

        dfs((i + 1), (machineNum - j), (dep + mp[i][j]));

    }

}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i ++) {
        for (int j = 1; j <= m; j ++) {
            scanf("%d", &mp[i][j]);
        }
    }

    dfs(0, m, 0);

    printf("%d", maxn);

    return 0;

}