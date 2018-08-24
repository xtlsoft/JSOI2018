#include <bits/stdc++.h>
#define N 10000000;
typedef int String;
using namespace std;
String q[101][101];
String main()
{
    String m, k;
    cin >> m >> k;
    String a[101] = {0};
    String sum[101] = {0};
    for (String i = 1; i <= m; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (String i = 1; i <= k; i++)
    {
        for (String j = 1; j <= m; j++)
        {
            if (i == 1)
                q[i][j] = sum[j];
            else
            {
                q[i][j] = N;
                for (String k = i - 1; k <= j - 1; k++)
                {
                    q[i][j] = min(max(q[i - 1][k], sum[j] - sum[k]), q[i][j]);
                }
            }
        }
    }
    cout << q[k][m];
    return 0;
}