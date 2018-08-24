#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getLIS2(int n, vector<int> s) {

    int i, j;
    int f[10010];

    for (i = 0; i<n; ++i) f[i] = 1;

    for (i = 1; i<n; i++) {
        for (j = 0; j<i; j++) {
            if(s[j] >= s[i]) {
                if (f[i] <= f[j]) {
                    f[i] = f[j] + 1;
                }
            }
        }
    }

    int ans = 0;

    for (i = 0; i < n; i ++) {
        if (f[i] > ans) {
            ans = f[i];
        }
    }

    return ans;

}

int getLIS(int n, vector<int> s) {

    int i, j;
    int f[10010];

    for (i = 0; i<n; ++i) f[i] = 1;

    for (i = 1; i<n; i++) {
        for (j = 0; j<i; j++) {
            if(s[j] <= s[i]) {
                if (f[i] <= f[j]) {
                    f[i] = f[j] + 1;
                }
            }
        }
    }

    int ans = 0;

    for (i = 0; i < n; i ++) {
        if (f[i] > ans) {
            ans = f[i];
        }
    }

    return ans;

}

int main() {

    int n;
    cin >> n;

    vector<int> s;

    for (int i = 0; i < n; ++ i) {

        int tmp;

        cin >> tmp;

        s.push_back(tmp);

    }

    std::cout << getLIS2(n, s);

    std::cout << endl << getLIS(n, s);

    return 0;

}