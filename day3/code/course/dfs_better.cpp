#include <iostream>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
const int BORDER = 100000;
const int MAXN = BORDER;

int minn = INF;
bool flag;
int k;
int f[MAXN];
bool vis[MAXN];

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

void dfs(int now, int cow, int count) {

    if (count >= f[now]) return;
    f[now] = count;

    if (count >= minn) return;

    if(now == cow) {
        minn = min(count, minn);
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
        if (nx >= 0 && nx <= min(2 * k, BORDER) && !vis[nx]) {
            vis[nx] = true; // 判重
            dfs(nx, cow, count + 1);
            vis[nx] = false; // 回溯
        }
    }

}

int main () {

    flag = false;

    memset(f, INF, sizeof(f));

    int n;
    cin >> n >> k;

    if (n >= k) {
        cout << (n - k) << endl;
        return 0;
    }

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