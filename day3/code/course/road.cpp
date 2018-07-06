#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

int n, m;
const int MAXN = 10000 + 10;

vector<int> v[MAXN], v1[MAXN]; // 正反邻接表

int s, t;

bool vis[MAXN], vis1[MAXN]; // 染色标记

struct Node {
    int x, steps;
    Node(int _x, int _steps) : x(_x), steps(_steps) {};
};

queue<Node> q;
bool flag;

void dfs(int x) {

    vis1[x] = true;
    
    for (int i = 0; i < v1[x].size(); ++ i) {
        int j = v1[x][i]; // 儿子编号
        if(!vis1[j]) dfs(j);
    }

}

void bfs(int s) {
    q.push(Node(s, 0));
    vis[s] = true; // 访问标记
    while (!q.empty()) {
        Node curr = q.front();
        q.pop();
        int x = curr.x;
        if (x == t) {
            cout << curr.steps << endl;
            flag = true;
            break;
        }else for(int i = 0; i < v[x].size(); ++ i) {
            int j = v[x][i];
            if (!vis[j]) {
                bool ok = true;
                for (int k = 0; k < v[j].size(); ++k) {
                    if (!vis1[v[j][k]]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    vis[j] = true;
                    q.push(Node(j, curr.steps + 1));
                }
            }
        }
    }
}

int main() {

    cin >> n >> m;

    flag = false;
    
    for (int i = 0; i < m; ++ i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y); // 正向图
        v1[y].push_back(x); // 反向图
    }

    cin >> s >> t;

    dfs(t);
    bfs(s);

    if(!flag) cout << 0 << endl;

    return 0;

}

/*
用 vector 建图。

数据量大，最后一个点超时。

反向图，终点为起点，将所有能到达的点打一个标记。找出未染色的坏点。

6 6
1 2
1 3
2 6
2 5
4 5
3 4
1 5
*/