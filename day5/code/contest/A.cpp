#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];
int b[100001];
int b2[100001];
int n, s, gmax, maxg;

int getMax(int j) {
    int cmax = 10000;
    cmax = 0;
    for (int i = 1; i < j; i++)
        if (a[j] > a[i] && b[i] > cmax)
            cmax = b[i];

    return cmax + 1;
}

int main() {
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> s;
        a[i] = s;
    }

    b[1] = 1;
    
    for (int i = 2; i <= n; i++)
        b[i] = getMax(i);
    
    for (int i = 1; i <= n; i++)
        b2[i] = b[i];

    for (int i = 2; i <= n; i++)
        b[i] = 0;

    reverse(a + 1, a + n + 1);

    for (int i = 2; i <= n; i++)
        b[i] = getMax(i);
    
    reverse(b + 1, b + n + 1);
    
    gmax = 1;
    
    for (int i = 1; i <= n; i++)
        if (b[i] + b2[i] >= gmax) {
            gmax = b[i] + b2[i];
            maxg = i;
        }

    cout << n - b[maxg] - b2[maxg] + 1;

    return 0;
    
}
