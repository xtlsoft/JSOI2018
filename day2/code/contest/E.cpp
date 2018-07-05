#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main () {

    vector<long long> arr;

    int n;

    cin >> n;

    for (long long i = 0; i<n; ++i) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    cin >> n;

    for(int i = 0; i < n; ++ i) {
        int tmp;
        cin >> tmp;
        int a = *(upper_bound(arr.begin(), arr.end(), tmp) -1 );
        int b = *(upper_bound(arr.begin(), arr.end(), tmp));
        int rslt;
        if ( a == b ) rslt = a;
        else if (abs(tmp - a) > abs(tmp - b)) rslt = b;
        else rslt = a;
        cout << rslt << endl;
    }

    return 0;

}

