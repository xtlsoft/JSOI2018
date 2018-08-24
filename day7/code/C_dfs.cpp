#include <iostream>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, x, y, mp[2002][2002], f[2002][2002];

const int nxi[4] = {0, 1, 0, -1};
const int nyi[4] = {1, 0, -1, 0};

void dfs(int i, int j, int dep) {

    if (dep >= f[i][j]) return;
    f[i][j] = dep;

    if (i == 0 || j == 0 || i > n || j > m) {
        return;
    }
    else for (int c = 0; c < 4; ++ c) {
        int nx, ny;
        nx = i + nxi[c];
        ny = j + nyi[c];

        int ndep;

        if (mp[i][j] != mp[nx][ny]) ndep = dep + 1;
        else ndep = dep;

        dfs(nx, ny, (ndep));
    }

}

int main() {

    ios::sync_with_stdio(true);

    memset(f, INF, sizeof(f));

    cin >> n >> m >> x >> y;

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            cin >> mp[i][j];
        }
    }

    dfs(x, y, 0);

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}