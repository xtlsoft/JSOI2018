#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cmp(vector<long long> a, vector<long long> b) {
    int pa = 0, pb = 0;
    while(pa < a.size() && pb < b.size() && a[pa] == b[pb]) {
        pa ++;
        pb ++;
    }

    if(a[pa] == b[pb]) {
        return (pa < a.size());
    }

    return a[pa] < b[pb];
}

int main() {

    vector<long long> a[1002];

    int n;
    cin >> n;

    for (int i=0; i<n; ++i) {
        int cnt;
        cin >> cnt;
        for (int j=0; j<cnt; ++j) {
            int tmp;
            cin >> tmp;
            a[i].push_back(tmp);
        }
        sort(a[i].begin(), a[i].end());
    }

    sort(a, a+n, cmp);

    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < a[i].size(); ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}
