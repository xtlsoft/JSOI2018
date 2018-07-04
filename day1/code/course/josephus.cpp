#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> v;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++ i) v.push_back(i+1);
    while(!v.empty()) {
        int k2 = k;
        if (k > v.size()) {
            k2 = k % v.size();
        }
        cout << v[k2 - 1] << " ";
        v.erase(v.begin() + k2 - 1);
        k2 += k - 1;
    }

    return 0;

}