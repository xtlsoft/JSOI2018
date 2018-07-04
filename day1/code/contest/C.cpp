#include <iostream>
#include <set>

using namespace std;

int main() {

    long long n, m;
    cin >> n >> m;

    multiset<long long> arr[n + 1];

    for (long long i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        arr[x].insert(y);
    }

    for (long long i = 1; i <= n; ++i) {

        cout << arr[i].size() << " ";
        multiset<long long>::iterator it;

        for (it = arr[i].begin(); it != arr[i].end(); ++ it) {
            cout << (*it) << " ";
        }

        cout << endl;

    }

    return 0;

}