#include <iostream>
#include <string>
#include <map>

using namespace std;

int main () {

    int n, q;
    cin >> n >> q;

    map<string, string> mp;

    for (int i = 0; i < n; ++ i) {
        string k, v;
        cin >> k >> v;
        mp[k] = v;
    }

    for (int i = 0; i < q; ++ i) {
        string tmp;
        cin >> tmp;
        cout << mp[tmp] << endl;
    }

    return 0;

}