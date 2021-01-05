#include <stdio.h>

int main()
{
    int i, j;
    long long a[3][3];
    for (i = 0; i < 3;i++)
        for (j = 0; j < 3; j++)
            scanf("%llu", &a[i][j]);
    long long A = a[0][0] * (a[2][2] * a[1][1] - a[1][2] * a[2][1]);
    long long B = a[0][1] * (a[2][2] * a[1][0] - a[1][2] * a[2][0]);
    long long C = a[0][2] * ( - a[1][1] * a[2][0] + a[1][0] * a[2][1]);
    printf("%lld", A - B + C);
}