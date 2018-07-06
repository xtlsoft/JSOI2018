#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1000 + 10;
const int INF = 0x3f3f3f3f;
const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int color[MAXN][MAXN];
int m;
bool vis[MAXN][MAXN];
int minn = INF;
bool flag;
int f[MAXN][MAXN];

int min(int a, int b) {
    return (a < b) ? a : b;
}

void dfs(int x, int y, int total, bool hasMagic) {

    if (total >= f[x][y]) {
        return;
    }
    f[x][y] = total;

    if (total >= minn) {
        return;
    }
    
    if (x == m && y == m) {
        minn = min(minn, total);
        flag = true;
    } else for (int i = 0; i < 4; ++ i) {
        
        int newx = x + dir[i][0];
        int newy = y + dir[i][1];

        if (newx < 1 || newx > m || newy < 1 || newy > m)
            continue;

        if (!vis[newx][newy]) {
            vis[newx][newy] = true;
            if (color[newx][newy] != -1) {
                if (color[x][y] == color[newx][newy]) {
                    if (!hasMagic) color[x][y] = -1; // Another way.
                    dfs(newx, newy, total, true);
                } else {
                    if (!hasMagic) color[x][y] = -1; // Another way.
                    dfs(newx, newy, total + 1, true);
                }
            } else {
                if (hasMagic) {
                    color[newx][newy] = color[x][y];
                    dfs(newx, newy, total + 2, false);
                } else {
                    if (!hasMagic) color[x][y] = -1; // Another way.
                    return;
                }
            }
        } else {
            continue;
        }
    }

}

int main() {

    memset(color, -1, sizeof(color));
    memset(f, INF, sizeof(f));

    int n;

    flag = false;

    cin >> m >> n;

    for (int i = 1; i <= n; ++ i) {
        int x, y, colour;
        cin >> x >> y >> colour;
        color[x][y] = colour;
    }
    
    vis[1][1] = true;

    dfs(1, 1, 0, true);

    flag ? (cout << minn << endl) : (cout << 0 << endl);

    return 0;

}