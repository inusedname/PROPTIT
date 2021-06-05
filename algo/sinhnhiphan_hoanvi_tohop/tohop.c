#include <stdio.h>

void IN(int k, int th[])
{
    for (int i = 1; i <= k; i++)
        printf("%d", th[i]);
    printf(" ");
}

int main()
{
    int n, k, i;
    scanf("%d%d", &n, &k);
    int th[100];
    for (int i = 1; i <= k; i++)
        th[i] = i;
    IN(k, th);
    while (1)
    {
        i = k;
        while (i > 0 && th[i] == n - k + i)
            i--;
        if (i == 0)
            break;
        th[i]++;
        for (int j = i + 1; j <= k; j++)
            th[j] = th[j - 1] + 1;
        IN(k,th);
    }
}