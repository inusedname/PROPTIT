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
    int dem = 0;
    for (int i = k; i >= 1; i--)
        th[i] = n - dem++;
    IN(k, th);
    while (1)
    {
        i = 1;
        while (i <= k && th[i] == i)
            i++;
        if (i > k)
            break;
        th[i]--;
        int dem = 0;
        for (int j = k; j > i; j--)
            th[j] = n - dem++;
        IN(k, th);
    }
}