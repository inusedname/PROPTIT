#include<stdio.h>

int min(int i,int j)
{
    if (i>j)
        return j;
    else
        return i;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            if (j!=n)
            {
                printf("%d ", n + 1 - min(i, j));
            }
            else
            {
                printf("%d", n + 1 - min(i, j));
            }
        }
        printf("\n");
    }
}