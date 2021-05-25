#include <stdio.h>
#include <math.h>
int min (int i,int j)
{
    if (i<j)
        return i;
    else
    {
        return j;
    }
        
}
int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = -n+1; i < n;i++)
    {
        for (j = -n+1; j < n;j++)
        {
            printf("%c", 97 + min(abs(i), abs(j)));
        }
        printf("\n");
    }
}