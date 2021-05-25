#include <stdio.h>
int main()
{
    int n,m;
    scanf("%d", &n);
    for (int i = 1; i <= (2*n)-1; i++)
    {
        for (int j = 1; j <= n;j++)
        {
            if (i>n)
            {
                m = i - ((i - n) * 2);
            }
            else
            {
                m = i;
            }
            if (m+j<=n)
                printf("~");
            else
                printf("*");
            }
        printf("\n");
    }
}