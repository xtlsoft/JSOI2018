#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 1000 + 10;
int T;
long long n, h, r;

struct Node {
    long long x, y, z;
}holes[MAXN];

bool flag = false;
bool vis[MAXN];

// 检查两洞可否走
bool check(long long a, long long b) {
    return ( ( pow(holes[a].x - holes[b].x, 2) + 
                   pow(holes[a].y - holes[b].y, 2) + 
                   pow(holes[a].z - holes[b].z, 2) ) <= pow(2 * r, 2) );
}

// 第 x 个洞
void dfs(long long x) {
    vis[x] = true;
    if (holes[x].z >= h - r && holes[x].z <= h+r) {
        flag = true;
    } else for(long long i = 1; i <= n; ++ i) {
        if (check(x, i) && !vis[i]) {
            dfs(i);
        }
    }
}

int main() {

    cin >> T;

    // 循环输入 T 组数据
    while (T --) {
        memset(vis, false, sizeof(vis));
        flag = false;
        cin >> n >> h >> r;
        for (long long i = 0; i < n; ++ i) {
            cin >> holes[i].x >> holes[i].y >> holes[i].z;
        }

        for (long long i = 1; i <= n; ++i) {
            if (holes[i].z >= -r && holes[i].z <= r && !vis[i]) {
                dfs(i);
                if(flag){
                    cout << "Yes" << endl;
                    break;
                }
            }
        }

        cout << "No" << endl;
    }

}