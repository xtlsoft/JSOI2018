#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, tmp = 0, tmp2 = 0;
    cin >> n;
    vector<int> m[100010];
    for (int i = 0; i < n; ++ i) {
        cin >> tmp;
        for (int j = 0; j < tmp; ++ j) {
            cin >> tmp2;
            m[i].push_back(tmp2);
        }
    }

    int maxn = 0, maxid = 0;

    for (int i = 0; i < n; ++ i) {
        int total = 0;
        for (int j = 0; j < m[i].size(); ++j) {
            total += m[m[i][j]].size();
        }
        if(total > maxn) {
            maxn = total;
            maxid = i + 2;
        }
    }

    cout << maxid << " " << maxn;

    return 0;

}