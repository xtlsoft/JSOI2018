#include <iostream>

using namespace std;

int main() {

    int n, k, arr[10010], cnt = 0, calc = 0;
    cin >> n >> k;

    for (int i=0; i<=k; ++i) {
        cin >> arr[i];
        if (n < arr[i]) {
            cout << "No Solution";
            return 0;
        }
    }

    for (int i = 0; i<=k; ++i) {
        calc += arr[i];
        if(i != k && calc + arr[i + 1] > n) {
            // cout << i << " " << calc << endl;
            cnt ++;
            calc = 0;
        }
    }

    cout << cnt;

    return 0;

}