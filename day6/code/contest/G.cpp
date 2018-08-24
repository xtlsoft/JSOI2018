#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main () {

    int n;
    cin >> n;

    for (int i = 0; i < n; ++ i) {

        int tmp;
        cin >> tmp;
        v.push_back(tmp);

    }

    int total = 0;

    while (v.size() > 1) {
        sort(v.begin(), v.end());

        v[1] = v[0] + v[1];

        total += v[1];

        v.erase(v.begin());
    }

    cout << total;

    return 0;

}