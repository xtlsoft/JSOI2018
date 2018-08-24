#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

struct Visit {
    bool visited;
    int family;
    Visit() {
        visited = false;
    }
};

bool matrix[102][102];
Visit vis[102];

set<int> family[102];
int curr = 0;

int cmp(set<int> a, set<int> b) {
    return a.size() > b.size();
}

int main() {

    memset(matrix, false, sizeof(matrix));

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; ++ i) {
        int x, y;
        cin >> x >> y;
        matrix[x][y] = matrix[y][x] = true;
    }

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            if (matrix[i][j]) {
                if (!vis[i].visited && !vis[j].visited) {
                    family[curr].insert(i);
                    family[curr].insert(j);
                    vis[i].visited = true;
                    vis[j].visited = true;
                    vis[i].family = curr;
                    vis[j].family = curr;
                    curr ++;
                } else if (vis[i].visited) {
                    family[vis[i].family].insert(j);
                    vis[j].visited = true;
                    vis[j].family = vis[i].family;
                } else if (vis[j].visited) {
                    family[vis[j].family].insert(i);
                    vis[i].visited = true;
                    vis[i].family = vis[j].family;
                }
            }
        }
    }

    sort(family, family + curr, cmp);

    int cnt = curr;

    for (int i = 1; i <= n; ++ i) {

        if (vis[i].visited == false) {
            ++cnt;
        }

    }

    cout << cnt << " " << family[0].size();

    return 0;

}
