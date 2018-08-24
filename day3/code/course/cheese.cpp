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

bool check(long long a, long long b) {
    return ( ( (holes[a].x - holes[b].x) * (holes[a].x - holes[b].x) + 
                   (holes[a].y - holes[b].y) * (holes[a].y - holes[b].y) + 
                   (holes[a].z - holes[b].z) * (holes[a].z - holes[b].z) ) <= (2 * r * 2 * r) );
}

void dfs(long long x) {
    vis[x] = true;
    if (holes[x].z >= h - r && holes[x].z <= h+r) {
        flag = true;
    } else for (long long i = 1; i <= n; ++ i) {
        if (check(x, i) && !vis[i]) {
            dfs(i);
        }
    }
}

int main() {

    cin >> T;

    while (T --) {
        memset(vis, false, sizeof(vis));
        flag = false;
        cin >> n >> h >> r;
        for (long long i = 1; i <= n; ++ i) {
            cin >> holes[i].x >> holes[i].y >> holes[i].z;
        }

        for (long long i = 1; i <= n; ++i) {
            if (holes[i].z >= -r && holes[i].z <= r && !vis[i]) {
                dfs(i);
            }
        }

        if(!flag)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }

}