#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> arr;

    for (int i = 0; i < n; ++ i) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    for (int i = 0; i < m; ++ i) {
        int f, b;
        cin >> f >> b;
        reverse(arr.begin() + f - 1, arr.begin() + b);
    }

    for (int i = 0; i < arr.size(); ++ i) {
        cout << arr[i] << " ";
    }

    return 0;

}