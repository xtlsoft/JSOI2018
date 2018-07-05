#include <iostream>

using namespace std;

int main () {

    int n;

    cin >> n;

    int arr[9999];
    for (int i = 0; i<n; ++i) {
        cin >> arr[i];
    }

    int left = 0, right = n - 1;
    int mid;

int a = 0;
cin >> a;

for (int an = 0; an < a; ++ a) {

    int x;
    cin >> x;

    while (left <= right) {

        mid = ( left + right ) / 2;
        
        if (x == arr[mid]) {
            cout << x;
            return 0;
        } else if (x > arr[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }

    }

    cout << arr[right]; // Because "right = left - 1".

}

    return 0;

}