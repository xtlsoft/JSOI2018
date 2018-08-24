#include <iostream>
#include <cstring>

using namespace std;

int n, m, mp[2002][2002] = {INF};
int f[2002][2002];
const int INF = 0x3f3f3f3f;
const int nx[4] = {0, 0, 1, -1};
const int ny[4] = {1, -1, 0, 0};

int dp(int x, int y) {

    if (f[x][y] != -1) return f[x][y];
    else {
        int minn = INF;
        for (int i = 0; i < 4; ++ i) {
            int newx = x + nx[i];
            int newy = y + ny[i];

            if (newx < 1 || newx > n || newy < 1 || newy > m || f[newx][newy] == -1) continue;

            int tmp1 = 0;

            if (mp[x][y] != mp[newx][newy]) ++tmp1;

            minn = min(minn, (dp(newx, newy) + tmp1));
        }
        f[x][y] = minn;
        return minn;
    }

}

int main() {

    memset(f, -1, sizeof(f));

    int x, y;

    cin >> n >> m >> x >> y;

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {

            cin >> mp[i][j];

        }
    }

    f[x][y] = 0;

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            dp(i, j) << " ";
        }

        cout << endl;
    }

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            cout << dp(i, j) << " ";
        }

        cout << endl;
    }

    return 0;

}