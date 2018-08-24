#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> v;

    int n, m;

    cin >> n >> m;
    for(int i = 1; i <= n; ++ i) v.push_back(i);

    int k = 0;

    int last = 0;

    while (!v.empty()) {
        k = (k + m - 1) % v.size();
        last = v[k];
        v.erase(v.begin() + k);
    }

    cout << last;

    return 0;

}