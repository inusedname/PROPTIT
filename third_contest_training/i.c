#include <stdio.h>
int main()
{
    int n, k;
    int i;
    scanf("%d%d", &n, &k);
    int temp;
    int dem = 0;
    for (i = 0; i < n;i++)
    {
        scanf("%d", &temp);
        if (k)
            if (temp%k==0)
                dem++;
    }
    printf("%d", dem);
}