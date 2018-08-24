#include <iostream>

using namespace std;

const int MAXN = 10000 + 10;

int mp[MAXN];

int getMax(int a, int b, int c = -2147483647) {
    int n = (a > b) ? a : b;
    return (n > c) ? n : c;
}

int dp(int n) {

    if (n == 0) return 0;
    else if (n == 1) return mp[1];
    else if (n == 2) return (getMax(0, dp(1)) + mp[2]);
    else if (n == 3) return (getMax(0, dp(1), dp(2)) + mp[3]);
    else {
        return (getMax(dp(n - 1), dp(n - 2), dp(n - 3)) + mp[n]);
    }

}

int main() {

    int n;
    
    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        cin >> mp[i];
    }

    cout << dp(n);

    return 0;

}