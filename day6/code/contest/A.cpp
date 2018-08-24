#include <iostream>

using namespace std;

struct Medicine {
    int time;
    int value;
    Medicine() {
        time = 0;
        value = 0;
    }
};

int main() {

    int t, m;

    cin >> t >> m;

    Medicine medicines[102];

    int f[102][1002] = {0};

    for (int i = 1; i <= m; ++ i) {

        cin >> medicines[i].time >> medicines[i].value;

    }

    for (int i = 1; i <= m; ++ i) {

        for (int j = 1; j <= t; ++ j) {

            if (j >= medicines[i].time)
                f[i][j] = max(f[i - 1][j], f[i - 1][j - medicines[i].time] + medicines[i].value);
            else
                f[i][j] = f[i-1][j];

        }

    }

    int maxn = 0;

    for (int i = 1; i <= m; ++ i) {
        for (int j = 0; j <= t; ++ j) {
            maxn = max(f[i][j], maxn);
        }
    }

    cout << maxn;

    return 0;

}