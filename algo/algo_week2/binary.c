#include <stdio.h>

void IN(int n, int np[])
{
    for (int i = 0; i < n; i++)
        printf("%d", np[i]);
    printf("\n");
}
int main()
{
    int n, i, j;
    scanf("%d", &n);
    int np[100] = {0};
    IN(n, np);
    while (1)
    {
        i = n - 1;
        while (i >= 0 && np[i] == 1)
            i--;
        if (i < 0)
            break;
        np[i] = 1;
        for (j = i + 1; j < n; j++)
            np[j] = 0;
        IN(n, np);
    }
}