#include <iostream>
#include <map>

using namespace std;

int main() {

    int n; cin >> n;

    map<int, int> mp;

    for (int i=0; i<n; ++i) {

        int cnt = 0;
        cin >> cnt;

        if (!mp.count(cnt)) {
            mp[cnt] = 1;
        }else{
            mp[cnt] ++;
        }

    }

    map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); ++it) {

        cout << it->first << " " << it->second << endl;

    }

    return 0;

}