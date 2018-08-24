// 错

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main () {

    int f[110][110];
    string x, y;

    cin >> x >> y;

    memset(f, 0, sizeof(f));

    int len1 = x.length(), len2 = y.length();

    // 可使用滚动数组

    for (int i = 1; i <= len1; ++ i) 
        for (int  j = 1; j <= len2; ++ j) 
            if (x[i-1] == y[i-1])
                f[i][j] = f[i-1][j-1] + 1;
            else
                f[i][j] = max(f[i-1][j],f[i][j-1]);

    cout << f[len1][len2] << endl; // 最后一个格子

}