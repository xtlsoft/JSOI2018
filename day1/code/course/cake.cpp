#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > v; // time, id

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; ++ i) {
        int x;
        cin >> x;
        v.push_back(make_pair(x, i));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++ i) {
        cout << (v[i].second + 1) << " ";
    }

    return 0;

}