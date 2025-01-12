#include <stdio.h>

int main()
{
    const int n = 5, m = 3;
    int i, j, k;
    int allocated[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}};
    int maxi[5][3] = {{3, 2, 2}, {7, 5, 3}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};

    int avail[3] = {3, 3, 3};
    int f[5] = {0}, ans[n], ind = 0;
    int need[n][m];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = maxi[i][j] - allocated[i][j];
        }
    }

    int y = 0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += allocated[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            printf("The System is not safe ");
            break;
        }
    }
    if (flag == 1)
    {
        printf("The system is safe");
        for (i = 0; i < n - 1; i++)
        {
            printf("P%d-> ", ans[i]);
        }
        printf("P%d", ans[n - 1]);
    }
    return 0;
}