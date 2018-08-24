#include <iostream>
#include <set>

using namespace std;

int main () {

    int n, c;
    cin >> n >> c;

    multiset<int> arr;

    for (int i=0; i<n; ++i) {
        int j;
        cin >> j;
        arr.insert(j);
    }

    multiset<int>::iterator it;

    int cnt = 0;

    for(it=arr.begin(); it != arr.end(); ++it) {
        int tmp = (*it) - c;
        cnt += arr.count(tmp);
    }

    cout << cnt;

    return 0;

}