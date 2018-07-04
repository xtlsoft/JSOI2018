#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100010];

int main() {

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int tmp;
        cin >> tmp;
        v[tmp].push_back(i + 1);
    }

    int maxn = -1, maxi = -1;

    for (int i = 1; i <= n; ++ i) {

        int total = 0;

        for (int j = 0; j < v[i].size(); ++ j) {
            
            total += v[v[i][j]].size();

        }

        if (total > maxn) {
            maxi = i;
        }
        maxn = (total > maxn) ? total : maxn;

    }

    cout << maxi << " " << maxn;

    return 0;

}