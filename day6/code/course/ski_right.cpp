#include <iostream>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int h[102][102] = {1};
int f[102][102] = {1};
int r, c;

int dfs(int x, int y) {

    if(f[x][y]) return f[x][y];

    int mx = 0; // max

    for (int i = 0; i < 4; i ++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 || nx > r || ny < 1 || ny > c) continue;
        if (h[nx][ny] < h[x][y]) 
            mx = max(mx, dfs(nx, ny));
    }

    f[x][y] = mx + 1; // 存表

    return f[x][y];
    
}

int main() {

    int x, y;

    cin >> x >> y;

    r = x, c = y;

    for (int i = 0; i < x; ++ i) {
        for (int j = 0; j < x; ++ j) {
            cin >> h[i][j];
        }
    }

    dfs(0, 0); // WIP, 从最高一个点开始搜索

    return 0;

}