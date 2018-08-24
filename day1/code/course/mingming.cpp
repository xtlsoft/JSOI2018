#include <iostream>
#include <set>

using namespace std;

int main() {

    int n;
    set<long long> vis;

    cin >> n;
    for (int i=1; i<=n; ++i) {
        long long x;
        cin >> x;
        vis.insert(x);
    }

    cout << vis.size() << endl;

    set<long long>::iterator it;
    for (it = vis.begin(); it != vis.end(); ++it) {
        cout << *it << " ";
    }

    return 0;

}