#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int m, s, c, id[10002] = {0}, delta[10002] = {0};
    cin >> m >> s >> c;

    for (int i = 0; i < c; ++ i) {
        cin >> id[i + 1];
    }

    int now = 1, count = 1, length = 0, curr = 1;

    sort(id + 1, id + c + 1);

    for (int i = 1; i < c; ++ i) {
        delta[i] = id[i + 1] - id[i];
    }

    while (true) {
        length = 0;
        curr = 1;
        count = 1;
        for (curr = 1; curr < c; ++ curr) {
            if (delta[curr] > now) {
                ++count;
            }
        }
        if (count <= m) {
            break;
            return 0;
        }

        ++now;
    }

    int i = 1;
    length = 0;
    while(i <= c) {
        int start = i;
        while (i <= (c - 1) && (id[i + 1] - id[i]) <= now) {
            ++i;
        }
        // cout << id[start] << " " << id[i] <<endl;
        length += id[i] - id[start] + 1;
        ++i;
    }

    if (count < m) {
        length -= now - 1;
    }

    cout << length;

    return 0;

}