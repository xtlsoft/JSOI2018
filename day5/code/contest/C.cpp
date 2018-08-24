#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct getLISRslt {
    int i;
    vector<int> s;
};

getLISRslt getLIS(int n, vector<int> s) {

    int i, j;
    int f[10010];
    int p[10010] = {-1};

    for (i = 0; i<n; ++i) f[i] = 1;

    for (i = 1; i<n; i++) {
        for (j = 0; j<i; j++) {
            if(s[j] >= s[i]) {
                if (f[i] <= f[j]) {
                    f[i] = f[j] + 1;
                    p[i] = j;
                }
            }
        }
    }

    int ans = 0;
    int k = 0;

    for (i = 0; i < n; i ++) {
        if (f[i] > ans) {
            ans = f[i];
            k = i;
        }
    }

    // cout << k << " ";

    vector<int> s2 = s;

    while (k != -1) {
        // cout << s[k] << " ";
        s2.erase(find(s2.begin(), s2.end(), s[k]));
        k = p[k];
    }

    getLISRslt re;

    re.i = ans;
    re.s = s2;

    return re;

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

    std::cout << getLIS(n, s).i;

    int cnt = 0;

    for (;!s.empty();) {

        s = getLIS(s.size(), s).s;

        ++cnt;

    }

    std::cout << endl << cnt;

    return 0;

}