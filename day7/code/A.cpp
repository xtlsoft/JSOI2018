#include <iostream>

using namespace std;

int main() {

    int n, atotal = 0, btotal = 0, tmp;
    
    cin >> n;

    for (int i = 0; i < n; ++ i) {
        cin >> tmp;
        atotal += tmp;
    }

    cin >> n;

    for (int i = 0; i < n; ++ i) {
        cin >> tmp;
        btotal += tmp;
    }

    if (atotal > btotal) cout << 'A' << endl;
    else cout << 'B' << endl;

    cout << atotal << " " << btotal;

    return 0;

}