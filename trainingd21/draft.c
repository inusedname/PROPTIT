#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    // CÂU 3A
    // for (int i = 0; i < n; i++)
    // {
    //     int m = n - 1;
    //     for (int j = -m; j <= m; j++)
    //     {
    //         if (abs(j) <= i)
    //             printf("*");
    //         else
    //             printf(" ");
    //     }
    //     printf("\n");
    // }

    // CÂU 3C
    // for (int i = 0; i < n; i++)
    // {
    //     int m = n - 1;
    //     for (int j = -m; j <= m; j++)
    //     {
    //         if (abs(j) == i || i == n - 1)
    //             printf("*");
    //         else
    //             printf(" ");
    //     }
    //     printf("\n");
    // }

    // CÂU 4B
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (i > j) // max (i,j)
    //             printf("%d ", i);
    //         else
    //             printf("%d ", j);
    //     }
    //     printf("\n");
    // }

    // CÂU 4C
    // int m = n - 1;
    // for (int i = -m; i <= m; i++)
    // {
    //     for (int j = -m; j <= m; j++)
    //     {
    //         if (abs(i) > abs(j)) // max (i,j)
    //             printf("%d ", abs(i) + 1);
    //         else
    //             printf("%d ", abs(j) + 1);
    //     }
    //     printf("\n");
    // }
}