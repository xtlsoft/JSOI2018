#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;
const int BORDER = 1000000;
const int MAXN = BORDER;

bool flag;
int n, k;

struct Node {
    int x, steps;
    Node(int x_input, int steps_input) : x(x_input), steps(steps_input) {};
};
queue<Node> q;
bool vis[MAXN];

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

void bfs() {

    q.push(Node(n, 0)); // 初始状态入队。农夫初始位置，steps = 0。
    vis[n] = true; // 起点判重

    while(!q.empty()){ // 判断队列非空
        Node curr = q.front(); // 存储队首
        q.pop(); // 已保存，可出队。不能忘记。

        if(curr.x == k) { // 当找到时
            cout << curr.steps << endl;
            break; // 第一个一定是最优的;
        } else for (int i = 1; i <= 3; ++ i ) {
            int nx;
            if(i == 1) nx = curr.x - 1;
            if(i == 2) nx = curr.x + 1;
            if(i == 3) nx = curr.x * 2;

            if(nx >= 0 && nx <= BORDER && !vis[nx]) {
                vis[nx] = true;
                q.push(Node(nx, curr.steps + 1));
            }
        }
    }

}

int main () {

    cin >> n >> k;

    bfs();

    return 0;

}

/*
x-1 x+1 2*x -> 1 分钟

5 17 
4
*/