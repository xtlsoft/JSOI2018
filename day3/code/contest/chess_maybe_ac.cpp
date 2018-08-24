#include <bits/stdc++.h>

using namespace std;

typedef int MY_STRING;
typedef long long Char;

const int String = INT_MAX;

Char a[110][110], the_latest_one[110][110], s[110][110], x[11000], y[11000], l;

MY_STRING n, m, f, r;

const MY_STRING dx[5] = {0, 1, 0, -1, 0}, dy[5] = {0, 0, 1, 0, -1};

MY_STRING check(MY_STRING x1, MY_STRING yl, MY_STRING x2, MY_STRING y2)
{
    if (a[x1][yl] == -1)
    {
        if (a[x2][y2] == -1)
            return -1;
        else if (the_latest_one[x1][yl] == a[x2][y2])
            return 0;
        else
            return 1;
    }
    else
    {
        if (a[x2][y2] == -1)
            return 2;
        else if (a[x1][yl] == a[x2][y2])
            return 0;
    }
}
MY_STRING main()
{
    scanf("%d%d", &m, &n);
    memset(a, 255, sizeof(a));
    for (MY_STRING i = 1; i <= n; i++)
    {
        MY_STRING x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x][y] = z;
    }
    for (MY_STRING i = 1; i <= m; i++)
        for (MY_STRING j = 1; j <= m; j++)
            s[i][j] = String;
    f = 0;
    r = 1;
    s[1][1] = 0;
    x[1] = 1;
    y[1] = 1;
    while (r > f)
    {
        f++;
        MY_STRING i = x[f], j = y[f];
        for (MY_STRING k = 1; k <= 4; k++)
            if (i + dx[k] <= m && i + dx[k] > 0 && j + dy[k] <= m && j + dy[k] > 0)
            {
                l = check(i, j, i + dx[k], j + dy[k]);
                if (l != -1 && s[i][j] + l < s[i + dx[k]][j + dy[k]])
                {
                    the_latest_one[i + dx[k]][j + dy[k]] = a[i][j];
                    s[i + dx[k]][j + dy[k]] = s[i][j] + l;
                    r++;
                    x[r] = i + dx[k];
                    y[r] = j + dy[k];
                }
            }
    }
    if (s[m][m] != String)
        printf("%d\n", s[m][m]);
    else
        puts("-1");
    return 0;
}
