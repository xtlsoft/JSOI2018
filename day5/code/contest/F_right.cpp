#include <iostream>
#include <algorithm>

using namespace std;

int x, y, map[102][102];
int vis[102][102];

struct Node {
    int x, y, tmp;
    void init(int _x, int _y, int _tmp) {
        x = _x, y = _y, tmp = _tmp;
    }
};

int cmp(Node a, Node b) {
    return a.tmp > b.tmp;
}

int main() {

    cin >> x >> y;

    int f[102][102] = {0};

    Node nodes[10010];
    int curr = 0;

    for (int i = 0; i < x; i ++) {
        for (int j = 0; j < y; j ++) {
            cin >> map[i][j];
            f[i][j] = 1;
            nodes[curr++].init(i, j, map[i][j]);
        }
    }

    sort (nodes, nodes + curr, cmp);

    int maxn1 = 0;

    for (int ac = 0; ac < 10; ++ac) {

        for (int d = 0; d < curr; ++ d) {
            int i = nodes[d].x;
            int j = nodes[d].y;
            for (int c = 0; c < 4; ++ c) {
                int nx = i, ny = j;
                switch (c) {
                    case 0:
                        nx += 1;
                        break;
                    case 1:
                        nx -= 1;
                        break;
                    case 2:
                        ny += 1;
                        break;
                    case 3:
                        ny -= 1;
                        break;
                }
                if (!(nx >= 0 && nx < x && ny >= 0 && ny < y)) {
                    continue;
                }
                if (map[nx][ny] < map[i][j]) continue;
                if(f[i][j] < (f[nx][ny] + 1))
                    // cout << nx+1 << " " << ny+1;
                f[i][j] = max(f[i][j], (f[nx][ny] + 1));
            }
        }

        maxn1 = max(maxn1, f[nodes[curr - 1].x][nodes[curr - 1].y]);

    }

    cout << maxn1;
    
    return 0;

}