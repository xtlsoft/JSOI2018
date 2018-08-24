#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

void doNothing() {
    // Really does nothing
}

struct Node {
    int x, y, steps;
    Node(int _x, int _y, int _steps) : x(_x), y(_y), steps(_steps) {};
};

int map[104][104];
queue<Node> q;
bool flag = false;

void bfs(int m, int n, int D) {

    q.push(Node(1, 1, 0));

    while (!q.empty()) {

        Node curr = q.front();
        q.pop();

        if (curr.x == m && curr.y == m) {
            flag = true;
            cout << curr.steps << endl;
            return;
        } else for (int i = 0; i < (4 + D * 4); ++ i) {

            int nx, ny;

            if(i < 4) switch (i) {
                case 0:
                    nx = curr.x - 1;
                    break;
                case 1:
                    nx = curr.x + 1;
                    break;
                case 2:
                    ny = curr.y - 1;
                    break;
                case 3:
                    ny = curr.y + 1;
                    break;
            } else {
                int tmp123 = i - 3;
                int tmp1234 = tmp123 % 4;
                int tmp12345 = tmp123 / 4;
                switch (tmp1234) {
                    case 0:
                        nx = curr.x + tmp12345;
                        break;
                    case 1:
                        nx = curr.x - tmp12345;
                        break;
                    case 2:
                        ny = curr.y + tmp12345;
                        break;
                    case 3:
                        ny = curr.y - tmp12345;
                        break;
                }
            }

            if (nx < 1 || nx > m || ny < 1 || ny > n || map[nx][ny]) doNothing();
            else q.push(Node(nx, ny, curr.steps + 1));

        }

    }

}

int main() {

    int m, n, D;

    cin >> m >> n >> D;

    for (int i = 1; i <= m; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            // cout << m << n << endl;
            char tmp;
            tmp = getchar();
            while(tmp != 'P' && tmp != 'L') tmp = getchar();
            if(tmp == 'P') map[i][j] = 0;
            else map[i][j] = 1;
        }
    }

    bfs(m, n, D);

    if (!flag) cout << "impossible" << endl;

    return 0;

}