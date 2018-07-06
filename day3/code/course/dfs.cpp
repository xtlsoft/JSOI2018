#include <iostream>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
const int BORDER = 100000;
const int MAXN = BORDER;

int minn = INF;
bool flag;
bool vis[MAXN];

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

void dfs(int now, int cow, int count) {

    if(now == cow) {
        minn = min(now, minn);
        flag = true;
    }

    else for(int i = 0; i < 3; ++ i) {
        int nx;
        switch (i) {
            case 0:
                nx = now + 1;
                break;
            case 1:
                nx = now - 1;
                break;
            case 2:
                nx = now * 2;
                break;
        }
        if (nx >= 0 && nx <= BORDER && !vis[nx]) {
            vis[nx] = true; // 判重
            dfs(nx, cow, count + 1);
            vis[nx] = false; // 回溯
        }
    }

}

int main () {

    flag = false;

    int n, k;
    cin >> n >> k;

    vis[n] = false;

    dfs(n, k, 0);

    flag ? (cout << minn << endl) : (cout << -1 << endl);

    return 0;

}

/*
x-1 x+1 2*x -> 1 分钟

5 17 
4
*/