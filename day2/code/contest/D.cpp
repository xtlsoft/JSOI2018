#include <iostream>

using namespace std;

int main () {

    int n, arr[10004] = {0}, curr = 0, has[52] = {0};

    cin >> n;

    while(n != 0 && n != 1) {
        int a, b;
        a = n / 2;
        b = n - a;
        if(a == 1 || b == 1){
            break;
        }
        arr[curr++] = a;
        n = b;
    }

    arr[curr++] = n;

    int rslt = 1;
    if(!curr) rslt = 0;
    // rslt = 1;
    for(int i = 0; i < curr; ++ i) {
        // cout << arr[i] << endl;
        rslt *= arr[i];
    }

    cout << rslt;

    return 0;

}