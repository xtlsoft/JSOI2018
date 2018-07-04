#include <iostream>
#include <set>

using namespace std;

int main() {

    set<long long> v;

    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        v.insert(tmp);
    }

    int x;
    cin >> x;

    int count = 0;

    set<long long>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        int tmp = x - *it;
        if (tmp <= *it) break;
        if (v.count(tmp)) {
            count ++;
        }
    }

    cout << count;
    
    return 0;

}